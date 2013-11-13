#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#define SLEEP 2
int hydrogen,oxygen,sites,thresold;

pthread_t *workers;

sem_t s_resource;
sem_t s_thresold;
sem_t *s_sites;
bool *busy;
int *energy;


void *produceWater(void* threadId){
	long threadName;
	
	threadName=(long ) threadId;
	while(1){

		sem_wait(&s_resource);

		if( busy[threadName] ){
			sem_post(&s_resource);
			sleep(SLEEP);
			continue;
		}

		sem_wait(&s_sites[threadName]);

		busy[threadName]=true;

		if( threadName != sites-1 ){
			if( busy[threadName + 1] ) //right busy
			{
				sem_post(&s_sites[threadName]);
				busy[threadName]=false;
				sem_post(&s_resource);
				sleep(SLEEP);
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
				sleep(SLEEP);
				continue;
			}

			sem_wait(&s_sites[threadName-1]);// lock left
			busy[threadName - 1]=true;
		}



		sem_wait(&s_thresold);// check thresold


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

		energy[threadName]++;


		printf("site - %ld hydrogen - %d oxygen - %d energy-%d\n",threadName+1,hydrogen,oxygen,energy[threadName]);


		sem_post(&s_resource);

		sleep(3);

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
	energy=new int[sites];

	// initialize semaphores...
	sem_init(&s_thresold,0,thresold);

	sem_init(&s_resource,0,1);

	for(i=0;i<sites;i++)
		sem_init(&s_sites[i],0,1);


	for(i=0;i<sites;i++){

		st=pthread_create(&workers[i],NULL,produceWater,(void *)i);

		if(st){
			printf("Error in creating thread ");
			exit(-1);
		}
	}
	for(i=0;i<sites;i++){
		pthread_join(workers[i],NULL);
	}

	}
	else{
		printf("input format ./a.out <H> <O> <Sites> <Thresold>\n");
	}
	return 0;
}
