#include<iostream>
#include<sys/stat.h>
using namespace::std;

struct f_info{
int mt_mode;in(){
struct stat *buf=NULL;
stat(".",buf);
cout <<"hello c++";
return 0;
}
