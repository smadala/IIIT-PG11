#include <iostream>
#include <string>
using namespace::std;
int main(int argc, char ** argv)
{
    std::string default_console = "\033["+itoa(0)+"m";
    for (int i = 30; i <= 37; i++)
    {
        std::string color = "\033[0;"+itoa(i)+"m";

        std::cout<<color<<"test "<<i<<std::endl;

        color = "\033[1"+itoa(i)+"m";

        std::cout<<color<<"test "<<i<<" bold"<<std::endl;
        std::cout<<default_console<<std::endl;

    }

    std::cout << "Done" << std::endl;

    return 0;
}
