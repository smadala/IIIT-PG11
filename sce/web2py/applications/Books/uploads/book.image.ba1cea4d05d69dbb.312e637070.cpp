#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int numPath,refreshHour,tank=0;
	long long int time=0;
	int dist[1001],sup[1001];
	cin>>numPath;
	cin>>refreshHour;
	for(int i=1;i<=numPath;i++){
		cin>>dist[i];
	}
	for(int i=1;i<=numPath;i++){
		cin>>sup[i-1];
	}
	for(int i=1;i<=numPath;i++){

		tank=tank+sup[i-1];

		while(tank < dist[i] ){

			time+=refreshHour;
			tank+=sup[i-1];
			cout<<time<<" increase  "<<tank<<endl;
		}
		cout<<time<<" before  "<<tank<<endl;
		time+=dist[i];
		tank-=dist[i];
		cout<<time<<" after "<<tank<<endl;
	}
	cout<<time<<endl;
	return 0;
}

