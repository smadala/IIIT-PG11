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
void *produceWater(void* threadId){
	long threadName;
	threadName=(long ) threadId;
/*	printf("hello %ld\n",threadName);
	pthread_exit(NULL);*/
	while(1){
		//printf("while start %ld\n",threadName);	

		sem_wait(&s_resource);

		sem_wait(&s_sites[threadName]);

		if( threadName != sites-1 )
			sem_wait(&s_sites[threadName + 1]);//lock right

		if( threadName != 0)
			sem_wait(&s_sites[threadName-1]);// lock left



		sem_wait(&s_thresold);// check thresold

//		sem_wait(&s_resource);

		if(hydrogen < 2 || oxygen < 1){
			sem_post(&s_resource);

			sem_post(&s_thresold);

			if( threadName != 0)
				sem_post(&s_sites[threadName-1]);// lock left

			if( threadName != sites-1 )
				sem_post(&s_sites[threadName + 1]);//lock right

			sem_post(&s_sites[threadName]);

			pthread_exit(NULL);

		}

		hydrogen-=2;

		oxygen--;

		printf("site - %ld hydrogen - %d oxygen - %d\n",threadName,hydrogen,oxygen);

//		printf(" %ld \t",threadName);

		sem_post(&s_resource);

		sleep(3);

		sem_post(&s_thresold);

		if( threadName != sites-1 )
			sem_post(&s_sites[threadName + 1]);//lock right

		if( threadName != 0)
			sem_post(&s_sites[threadName-1]);// lock left


		sem_post(&s_sites[threadName]);

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

	// initialize semaphores...
	sem_init(&s_thresold,0,thresold);

	sem_init(&s_resource,0,1);

	for(i=0;i<sites;i++)
		sem_init(&s_sites[i],0,1);


	for(i=0;i<sites;i++){

		st=pthread_create(&workers[i],NULL,produceWater,(void *)i);
		//printf("created thread %ld \n",i);	

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
