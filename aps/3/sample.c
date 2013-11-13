onversation started September 15

9/15, 12:24am
Satya Madala
char *home = getenv("HOME");
 93         string h=home;
 94         h=h+"/.yshellrc";
 95         //cout<<h<<endl;
 96         ifstream infile(h.c_str());
 97         while(getline(infile,h))
Today

11:52pm
Arpit Jaiswal
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
char a[14];
int rec(int l,int l1)
{ 
 int i,sum=0,temp;
     i=l1-l;
     if(((int)a[i]-48)>=0 && ((int)a[i]-48)<3)
      {
       sum=0;
       }
      if(((int)a[i]-48)>3&&((int)a[i]-48)<7)
      {
       sum=pow(3,l-1);
       }
       if(((int)a[i]-48)>7&&((int)a[i]-48)<9)
      {
        sum=2*pow(3,l-1);
       }
      if(((int)a[i]-48)==3 && l!=1)
      {
        
        sum=rec(l-1,l1) ;
        }
        if(((int)a[i]-48)==7 && l!=1)
      {
        temp=pow(3,l-1);
        sum=temp+rec(l-1,l1);
       }
       if(((int)a[i]-48)==9 && l!=1)
      {
        temp=2*pow(3,l-1);
        sum=temp+rec(l-1,l1);
       }
       if(((int)a[i]-48)==3 && l==1)
      {
        sum=1;
        }
        if(((int)a[i]-48)==7 && l==1)
      {
        sum=2; 
      }
       if(((int)a[i]-48)==9 && l==1)
      {
        sum=3;
       }
      //cout<<"sum"<<i<<"="<<sum<<endl;
      return sum;
   
}
int rec1(int l)
{
int i,temp,sum=0;
  for(i=1;i<=l;i++)
  {
   temp=pow(3,i);
   sum=sum+temp;
  }
return sum;
}
int main()
{
int l,ans,ans1;
//a="1";
while(1)
{
cin>>a;
if(a[0]=='0')
break;
l=strlen(a);
ans=rec(l,l);
ans1=rec1(l-1);
cout<<ans+ans1<<"\n";
}
return 0;
}
