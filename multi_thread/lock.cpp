#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
using namespace std;
int a = 0;
mutex mt;
void fun()
{
    // mt.lock();
    for(int i=0;i<1000000;i++)
    {
        a=a+1;
    }
    // mt.unlock();
}
int main()
{
    
    thread t1(fun);
    thread t2(fun);
    this_thread::sleep_for(chrono::seconds(10));
    cout<<a<<endl;
    t1.join();
    t2.join();
    return 0;
    
}