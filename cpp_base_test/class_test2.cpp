/*拷贝构造函数、移动构造函数、运算符重载*/
#include <iostream>
using namespace std;
class A{
public:
    A(int num){
        cout << "using A constructor " << endl;
        p = new int(num);
    }
    ~A(){
        delete p;
        cout << "using A destructor " << endl;
    }
    /*拷贝构造函数。可接受的参数有：左值、常量左值、右值、常量右值*/
    A(const A& a){
        p = new int(*(a.p));
        cout << "using A copy constructor " << endl;
    }

    /*移动构造函数：参数为右值引用，右值或将亡值，尤其是调用函数return时*/
    A(A&& a)
    {
        cout << "using A move constructor" << endl;
        p = a.p;
        a.p = nullptr;
    }

    /*运算符重载：=*/
    A operator=(const A& a){
        this->p = new int(*(a.p));
        return *this;
    }
    /*运算符重载：+*/
    A operator+(const A& a){
        A a_(0);
        (a_.p) = new int(*(this->p) + *(a.p));
        return a_;
    }
public:
    int* p ;
};
A func(A a){
    cout<< "using func" << endl;
    return a;
}
int main()
{
    {
        A a1(3);
        A a2(a1); //拷贝构造函数场景1：a2未进行过初始化，用a1初始化a2调用拷贝构造函数
        A a3(4);
        a3 = a1; //a3已经进行过初始化，用a1对a3进行赋值调用 “=” 运算法，如果未对“=”进行重载，调用默认的赋值运算符，直接复制地址，引起重复释放内存

        A a4 = a1 + a3; //调用拷贝构造函数和“+”运算符
        cout <<a1.p << " :"<< *(a1.p) <<endl;
        cout <<a2.p << " :"<< *(a2.p) <<endl;
        cout <<a3.p << " :"<< *(a3.p) <<endl;
        cout <<a4.p << " :"<< *(a4.p) <<endl;
    }

    cout<<"*********************************************"<<endl;
    {
        A a1(3);
        A a2=func(a1);//函数值传递参数为A的对象，调用拷贝构造函数；返回值为A的对象，且函数中的对象即将消失，调用移动构造函数
    }

    cout<<"*********************************************"<<endl;

    
    return 0;
}
