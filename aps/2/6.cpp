#include<iostream>
using namespace::std;
void find(int p, long long int q){
static int res[][4]={{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1}
                     ,{8,4,2,6},{9,1}};
static int n[]={1,1,4,4,2,1,1,4,4,2};
if(p==0){
cout<<0<<endl;
return;
}
if(q==0){
cout<<1<<endl;
return;
}
cout << res[p%10][(q%n[p%10]==0)?n[p%10]-1:q%n[p%10]-1] <<endl;
}
int main(){
long long int q;
int p,t;
cin>>t;
while(t>0)
{
cin>>p>>q;
find(p,q);
t--;
}
return 0;
}
