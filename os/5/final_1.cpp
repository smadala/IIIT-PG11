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
int *energy;

int getSemValue(sem_t s){
	int val;
	sem_getvalue(&s,&val);
	return val;
}
void *produceWater(void* threadId){
	long threadName;
	int hl,ol,en;
	
	threadName=(long ) threadId;
	while(1){

		sem_wait(&s_resource);

		if( ! getSemValue(s_sites[threadName]) ){
			sem_post(&s_resource);
			continue;
		}

		sem_wait(&s_sites[threadName]);


		if( threadName != sites-1 ){
			if( ! getSemValue(s_sites[threadName + 1]) ) //right busy
			{
				sem_post(&s_sites[threadName]);
				sem_post(&s_resource);
				continue;
			}
		}

		if( threadName != 0){

			if(!getSemValue(s_sites[threadName - 1]) ) //left busy
			{
				sem_post(&s_sites[threadName]);
				sem_post(&s_resource);
				continue;
			}
		}



		sem_wait(&s_thresold);// check thresold


		if(hydrogen < 2 || oxygen < 1){
			sem_post(&s_resource);

			sem_post(&s_thresold);

			sem_post(&s_sites[threadName]); // release self

			pthread_exit(NULL);

		}

		hydrogen-=2;

		hl=hydrogen;

		ol=--oxygen;

		en=++energy[threadName];


	//	printf("site - %ld hydrogen - %d oxygen - %d energy-%d\n",threadName+1,hydrogen,oxygen,energy[threadName]);


		sem_post(&s_resource);

		sleep(3);
		printf("site - %ld hydrogen - %d oxygen - %d energy-%d\n",threadName+1,hl,ol,en);

		sem_post(&s_thresold);

		sem_post(&s_sites[threadName]);//release self
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
