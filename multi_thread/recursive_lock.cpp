#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
using namespace std;
mutex mt;

void funcA()
{
    mt.lock();
    for(int i=1;i<100;i++){
        cout<<"Love"<<endl;
    }
    mt.unlock();
}
void funcB()
{
    mt.lock();
    funcA();
    mt.unlock();
}
int main()
{
    funcA();
    funcB();
    return 0;
    
}