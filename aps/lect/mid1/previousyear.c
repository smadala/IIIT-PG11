#include<stdio.h>
int f(int x){
if(x==0)
 return 1;
else {
   g(x%2);
   f(x-1);
   return x*10;
}
}
int g(int y){
if(y==0)
  return 1;
else {
   f(y%2);
g(y-1);
return y/10;
}
}
int main(){
int a,b;
a=f(10);
b=g(10);
printf("%d %d",a,b);
/*int w=5,z=7;
float x=2.0, y=0.75;
printf("%f\n",y*z-w/x-w);
printf("%f\n",w%z/3*x+x-z);
printf("%f\n",(z^w)*(x*w-z));
printf("%d\n",z<<1&&1<<w);*/
return 0;
}
