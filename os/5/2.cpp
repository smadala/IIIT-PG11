#include<stdio.h4>
#include<stdlib.h>
#include<time.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t s_geek, s_ngeek, s_singer,mutex;

pthread_t *people;

int numGeeks,numNgeeks,numSingers;

int c_geek,c_ngeek,c_singer;

void board(){

	if( c_geek + c_ngeek + c_singer >= 4){
		if( c_geek >=2 && c_ngeek >= 1 && c_singer >=1 ){
			sem_post(&s_geek);
			sem_post(&s_geek);
			sem_post(&s_ngeek);
			sem_post(&s_singer);
			c_geek-=2;
			c_ngeek--;
			c_singer--;
			printf("geek 2 nongeek 1 singer 1\n");
		}
		else if(c_geek >=1 && c_ngeek >= 2 && c_singer >= 1){
			sem_post(&s_geek);
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_singer);
			c_ngeek-=2;
			c_geek--;
			c_singer--;
			printf("geek 1 nongeek 2 singer 1\n");
		}
		else if(c_geek >=2 && c_ngeek >= 2 && c_singer >= 0){
			sem_post(&s_geek);
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_geek);
			c_ngeek-=2;
			c_geek-=2;
			printf("geek 2 nongeek 2 singer 0\n");
		}
		else if(c_geek >=3 && c_ngeek >= 0 && c_singer >= 1){
			sem_post(&s_geek);
			sem_post(&s_geek);
			sem_post(&s_geek);
			sem_post(&s_singer);
			c_geek-=3;
			c_singer--;
			printf("geek 3 nongeek 0 singer 1\n");
		}
		else if(c_geek >=0 && c_ngeek >= 3 && c_singer >= 1){
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_singer);
			c_ngeek-=3;
			c_singer--;
			printf("geek 0 nongeek 3 singer 1\n");
		}
		else if(c_geek >=0 && c_ngeek >= 4 && c_singer >= 0){
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			sem_post(&s_ngeek);
			c_ngeek-=4;
			printf("geek 0 nongeek 4 singer 0\n");
		}
		else if(c_geek >=4 && c_ngeek >= 0 && c_singer >= 0){
			sem_post(&s_geek);
			sem_post(&s_geek);
			sem_post(&s_geek);
			sem_post(&s_geek);
			c_geek-=4;
			printf("geek 4 nongeek 0 singer 0\n");
		}
		sleep(1);
	}
}

void* geekArrives(void *data){

	sem_wait(&mutex);
	c_geek++;
	board();
	sem_post(&mutex);
	sem_wait(&s_geek);
	pthread_exit(NULL);
}
void* nonGeekArrives(void *data){

	sem_wait(&mutex);
	c_ngeek++;
	board();
	sem_post(&mutex);
	sem_wait(&s_ngeek);
	pthread_exit(NULL);
}
void* singerArrives(void *data){

	sem_wait(&mutex);
	c_singer++;
	board();
	sem_post(&mutex);
	sem_wait(&s_singer);
	pthread_exit(NULL);

}

int main ( int argc,char** argv){

	if( argc == 4){
	numGeeks=atoi(argv[1]);
	numNgeeks=atoi(argv[2]);
	numSingers=atoi(argv[3]);

	

	int numPeople=numGeeks+ numNgeeks + numSingers;

	people=(pthread_t *)malloc(numPeople * sizeof(pthread_t));
	
	sem_init(&s_geek,0,0);
	sem_init(&s_ngeek,0,0);
	sem_init(&s_singer,0,0);

	sem_init(&mutex,0,1);

	int random;
	int i=0,g=numGeeks,n=numNgeeks,s=numSingers;

	srand(time(NULL));

	while(i<numPeople){
		
		random=rand()%3;

		if( g > 0 && random == 0){
			pthread_create(&people[i],NULL ,geekArrives,NULL);
			i++;
			g--;
		}
		else if( n > 0 && random == 1){
			pthread_create(&people[i],NULL ,nonGeekArrives,NULL);
			i++;
			n--;
		}
		else if( s > 0 && random == 2){
			pthread_create(&people[i],NULL ,singerArrives,NULL);
			i++;
			s--;
		}
	}

	pthread_exit(NULL);
	}else{
		printf(" input format ./.aout <geek> <nongeek> <singer> \n");
	}
	return 0;
}
