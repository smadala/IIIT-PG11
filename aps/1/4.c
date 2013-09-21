/*Find the sum of all numbers between L and U (both inclusive) such that they are divisible
by a or b.
As the output can be large,
print (output )mod (1000000007)
0<=L<U<=10^8
1<=a,b<=100
Input:
The First line of the input will contain 'T' the number of test cases to be followed. The next
T lines will contain 4 numbers each (L<space>U<space>A<space>B) where L is the
lower bound and U is the upper bound. And A and B are the two numbers.
Output:
Display the sum of all numbers divisible by A or B between L & U. Output each answer on
a saperate line.
Example:
Input:
2
0 10 2 5
10 20 3 5
output:
35
75

*/
#include<stdio.h>
int sumAll(int,int,int,int);
int main(){
int t,l,u,a,b;
scanf("%d",&t);
while(t>0){
scanf("%d",&l);
scanf("%d",&u);
scanf("%d",&a);
scanf("%d",&b);
printf("%d\n",sumAll(l,u,a,b));
t--;
}
return 0;
}
int sumAll(int l,int u,int a,int b){
int i,sum=0;

for(i=l==0?1:l;i<=u;i++){ //check boundary cond
if(i%a == 0)
break;
}
for(;i<=u;i=i+a)//check boundary cond
{
sum=(sum+i)%1000000007;
}
for(i=l;i<=u;i++)
{
if(i%b==0)
break;
}
for(;i<=u;i=i+b){
if(i%a!=0)
sum=(sum+i)%1000000007;
}
return sum;
}
