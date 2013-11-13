#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

int main(int argc, char *argv[])
{	
	int t=10;
	while(t>0){
	printf(" random -%d\n",rand());
	t--;
	}
}
