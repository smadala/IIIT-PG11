#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
int hydrogen,oxygen,sites,thresold;

pthread_t *workers;

sem_t s_resource;
sem_t s_thresold;
sem_t *s_sites;
bool *busy;
sem_t join;
pthread_t joinThread;

void* signal(void *){
	sem_wait(&join);
	pthread_exit(NULL);
}

void *produceWater(void* threadId){
	long threadName;
	
	threadName=(long ) threadId;
	pthread_join(joinThread,NULL);

/*	printf("hello %ld\n",threadName);
	pthread_exit(NULL);*/
	while(1){
		//printf("while start %ld\n",threadName);	

		sem_wait(&s_resource);

		printf("resource lock %ld\n",threadName);	

		sem_wait(&s_sites[threadName]);

		busy[threadName]=true;

		if( threadName != sites-1 ){
			if( busy[threadName + 1] ) //right busy
			{
				sem_post(&s_sites[threadName]);
				busy[threadName]=false;
				sem_post(&s_resource);
				sleep(1);
				continue;
			}

			sem_wait(&s_sites[threadName + 1]);//lock right
			busy[threadName + 1]=true;
		}

		if( threadName != 0){

			if( busy[threadName - 1] ) //left busy
			{
				sem_post(&s_sites[threadName]);
				busy[threadName]=false;
				sem_post(&s_sites[threadName+1]);
				busy[threadName+1]=false;
				sem_post(&s_resource);
				sleep(1);
				continue;
			}

			sem_wait(&s_sites[threadName-1]);// lock left
			busy[threadName - 1]=true;
		}



		sem_wait(&s_thresold);// check thresold

//		sem_wait(&s_resource);

		if(hydrogen < 2 || oxygen < 1){
			sem_post(&s_resource);

			sem_post(&s_thresold);

			if( threadName != 0){
				sem_post(&s_sites[threadName-1]);// release left
				busy[threadName-1]=false;
			}

			if( threadName != sites-1 ){
				sem_post(&s_sites[threadName + 1]);//release right
				busy[threadName+1]=false;
			}

			sem_post(&s_sites[threadName]); // release self
			busy[threadName]=false;

			pthread_exit(NULL);

		}

		hydrogen-=2;

		oxygen--;

//		printf("site - %ld hydrogen - %d oxygen - %d\n",threadName,hydrogen,oxygen);

//		printf(" %ld \t",threadName);

		sem_post(&s_resource);

		sleep(1);

		sem_post(&s_thresold);

		if( threadName != 0){
			sem_post(&s_sites[threadName-1]);// release left
			busy[threadName-1]=false;
		}

		if( threadName != sites-1 ){
			sem_post(&s_sites[threadName + 1]);//release right
			busy[threadName+1]=false;
		}
		sem_post(&s_sites[threadName]);//release self
		busy[threadName]=false;
	}
}
int main(int argc,char **argv){
	int st;
	long i;
	/*scanf("%d",&hydrogen);
	scanf("%d",&oxygen);
	scanf("%d",&sites);
	scanf("%d",&thresold);*/
	if( argc == 5){
	
	hydrogen=atoi(argv[1]);
	oxygen=atoi(argv[2]);
	sites=atoi(argv[3]);
	thresold=atoi(argv[4]);

	//number of thread
	workers=(pthread_t *)malloc(sites * sizeof(pthread_t));


	//semaphores for each site 
	s_sites=(sem_t *)calloc(sites,sizeof(sem_t));

	busy=new bool[sites];

	// initialize semaphores...
	sem_init(&join,0,0);
	sem_init(&s_thresold,0,thresold);

	sem_init(&s_resource,0,1);

	for(i=0;i<sites;i++)
		sem_init(&s_sites[i],0,1);

	pthread_create(&joinThread,NULL,signal,NULL);

	for(i=0;i<sites;i++){

		st=pthread_create(&workers[i],NULL,produceWater,(void *)i);
		//printf("created thread %ld \n",i);	

		if(st){
			printf("Error in creating thread ");
			exit(-1);
		}
	}
	sem_post(&join);
	for(i=0;i<sites;i++){
		pthread_join(workers[i],NULL);
	}

	}
	else{
		printf("input format ./a.out <H> <O> <Sites> <Thresold>\n");
	}
	return 0;
}
