#include <stdio.h>
#include <stdlib.h>
void calculateIt(int n, int M);
long long int** powerUp(long long int **a,long long int **b,int M);

int main()
{
	int n,M,x=1,y=2;
	scanf("%d %d",&n,&M);
	if(n==0)
		printf("%d\n",x%M);
	else if(n==1)
		printf("%d\n",y%M);
	else
		calculateIt(n,M);
	return 0;
	}

void calculateIt(int n,int M)
{
	long long int **a,**product;
	int f0=1,f1=2,i=0,j=0;
	long long int ans=0;
	a=(long long int** )malloc(3*sizeof(long long int *));
	product=(long long int** )malloc(3*sizeof(long long int *));
	while(i<3)
	{
		a[i]=(long long int* )malloc(3*sizeof(long long int));
		product[i]=(long long int* )malloc(3*sizeof(long long int));
		i=i+1;
	}
	i=0;
	while(i<3)
	{
		while(j<3)
		{
			if(i==j)
			product[i][j]=1;
			else
			product[i][j]=0;
			a[i][j]=0;
			j=j+1;
		}
		i++;
		j=0;	
	}
	a[0][0]=2;
	a[0][1]=5;
	a[0][2]=1;
	a[1][0]=1;
	a[2][2]=1;
	i=0;
	n=n-1;
	while(n>0)
	{
		if(n%2==1)
			product=powerUp(product,a,M);
		a=powerUp(a,a,M);
		n=n/2;	
	}
	ans=((product[0][0]*f1)%M+(product[0][1]*f0)%M+(product[0][2]*3)%M)%M;
	printf("%lld\n",ans);
}


long long int** powerUp(long long int **a,long long int **b,int M)
{
	int c=0,d=0,k=0,i=0;
	long long int sum=0;
	long long int **multiply;
	multiply=(long long int** )malloc(3*sizeof(long long int *));
	while(i<3)
	{
		multiply[i]=(long long int* )malloc(3*sizeof(long long int));
		i=i+1;
	}
	for(c=0;c<3;c++)
	{
		for(d=0;d<3;d++)
		{
			for(k=0;k<3;k++)
			{
				sum=(sum%M+(a[c][k]*b[k][d])%M)%M;
			}
			multiply[c][d]=sum;
			sum = 0;
		}
	}
	return multiply;
}
