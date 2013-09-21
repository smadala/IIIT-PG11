// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
using namespace::std;
int main ()
{
/* std::string pi = "pi is " + std::to_string(3.1415926);
  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
  std::cout << pi << '\n';
  std::cout << perfect << '\n'; */
/*ostringstream ostr;
float f = 1.2;
//int i = 3;
ostr << f ;//<< " + " i << " = " << f + i;   
string s = ostr.str();
cout<<s<<endl;*/
int st=0,sl=0,x;
for(x=192455,st=0; x != 0; x /= 10, st++);
if(st>sl){ sl=st; cout<<st<<endl;}
  return 0;
}
