#include<stdio.h>
#include<string.h>
#define OS 1024
void binary();
char c[10000000];
int main(){
int t;
scanf("%d",&t);
while(t>0){
scanf("%s",c);
binary();
t--;
}
return 0;
}
void binary()
{
/*char r[OS];
memset(r,'\0',OS);
int p=-1;*/
int i,flag=0;
/*if(c[0]!=0){
if(c[0]=='0'&&c[1]==0){
printf("%c\n",'0');
return;
}
*switch(c[0]){
//case '0': r[++p]='0';r[++p]='0';r[++p]='0';r[++p]='0';break;
case '1': r[++p]='1';break;
case '2': r[++p]='1';r[++p]='0';break;
case '3': r[++p]='1';r[++p]='1';break;
case '4': r[++p]='1';r[++p]='0';r[++p]='0';break;
case '5': r[++p]='1';r[++p]='0';r[++p]='1';break;
case '6': r[++p]='1';r[++p]='1';r[++p]='0';break;
case '7': r[++p]='1';r[++p]='1';r[++p]='1';break;
case '8': r[++p]='1';r[++p]='0';r[++p]='0';r[++p]='0';break;
case '9': r[++p]='1';r[++p]='0';r[++p]='0';r[++p]='1';break;
case 'A': r[++p]='1';r[++p]='0';r[++p]='1';r[++p]='0';break;
case 'B': r[++p]='1';r[++p]='0';r[++p]='1';r[++p]='1';break;
case 'C': r[++p]='1';r[++p]='1';r[++p]='0';r[++p]='0';break;
case 'D': r[++p]='1';r[++p]='1';r[++p]='0';r[++p]='1';break;
case 'E': r[++p]='1';r[++p]='1';r[++p]='1';r[++p]='0';break;
case 'F': r[++p]='1';r[++p]='1';r[++p]='1';r[++p]='1';break;
}
}else return;*/

for(i=0;c[i]!=0;i++){
switch(c[i]){
case '0': if(flag==1){printf("0000");}break;
case '1': if(flag==1){printf("0001");}else{printf("1");flag=1;}break;
case '2': if(flag==1){printf("0010");}else{printf("10");flag=1;}break;
case '3': if(flag==1){printf("0011");}else{printf("11");flag=1;}break;
case '4': if(flag==1){printf("0100");}else{printf("100");flag=1;}break;
case '5': if(flag==1){printf("0101");}else{printf("101");flag=1;}break;
case '6': if(flag==1){printf("0110");}else{printf("110");flag=1;}break;
case '7': if(flag==1){printf("0111");}else{printf("111");flag=1;}break;
case '8': if(flag==1){printf("1000");}else{printf("1000");flag=1;}break;
case '9': if(flag==1){printf("1001");}else{printf("1001");flag=1;}break;
case 'A': if(flag==1){printf("1010");}else{printf("1010");flag=1;}break;
case 'B': if(flag==1){printf("1011");}else{printf("1011");flag=1;}break;
case 'C': if(flag==1){printf("1100");}else{printf("1100");flag=1;}break;
case 'D': if(flag==1){printf("1101");}else{printf("1101");flag=1;}break;
case 'E': if(flag==1){printf("1110");}else{printf("1110");flag=1;}break;
case 'F': if(flag==1){printf("1111");}else{printf("1111");flag=1;}break;
}
}
if(flag==0)
printf("0");
printf("\n");
/*case '0': r[++p]='0';r[++p]='0';r[++p]='0';r[++p]='0';break;
case '1': r[++p]='0';r[++p]='0';r[++p]='0';r[++p]='1';break;
case '2': r[++p]='0';r[++p]='0';r[++p]='1';r[++p]='0';break;
case '3': r[++p]='0';r[++p]='0';r[++p]='1';r[++p]='1';break;
case '4': r[++p]='0';r[++p]='1';r[++p]='0';r[++p]='0';break;
case '5': r[++p]='0';r[++p]='1';r[++p]='0';r[++p]='1';break;
case '6': r[++p]='0';r[++p]='1';r[++p]='1';r[++p]='0';break;
case '7': r[++p]='0';r[++p]='1';r[++p]='1';r[++p]='1';break;
case '8': r[++p]='1';r[++p]='0';r[++p]='0';r[++p]='0';break;
case '9': r[++p]='1';r[++p]='0';r[++p]='0';r[++p]='1';break;
case 'A': r[++p]='1';r[++p]='0';r[++p]='1';r[++p]='0';break;
case 'B': r[++p]='1';r[++p]='0';r[++p]='1';r[++p]='1';break;
case 'C': r[++p]='1';r[++p]='1';r[++p]='0';r[++p]='0';break;
case 'D': r[++p]='1';r[++p]='1';r[++p]='0';r[++p]='1';break;
case 'E': r[++p]='1';r[++p]='1';r[++p]='1';r[++p]='0';break;
case 'F': r[++p]='1';r[++p]='1';r[++p]='1';r[++p]='1';break;
}
if(p>OS-4){
printf("%s",r);
memset(r,'\0',OS);
p=-1;
}
}
printf("%s\n",r);*/
}

