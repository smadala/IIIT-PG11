#include<stdio.h>
unsigned int msb321(unsigned int x);
int main(){
unsigned  int n;
while(1)
{
scanf("%u",&n);
if(n==0)
return 0;
printf("%u\n",msb321(n)-1);
}
}
unsigned int msb321(unsigned int x)
{
    static const unsigned int bval[] =
    {0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};

    unsigned int r = 0;
    if (x & 0xFFFF0000) { r += 16/1; x >>= 16/1; }
    if (x & 0x0000FF00) { r += 16/2; x >>= 16/2; }
    if (x & 0x000000F0) { r += 16/4; x >>= 16/4; }
    return r + bval[x];
}
