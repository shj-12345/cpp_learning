#include <iostream>
using namespace std;
class A{
    public:
        A(){cout<<"A::constructor"<<endl;}
        virtual void func(){cout<<"A::func"<<endl;}
        ~A(){cout<<"A::destructor"<<endl;}
        virtual void fund(){cout<<"A::fund"<<endl;}
};
class B:public A{
    public:
        //B(){func();}
        B(){cout<<"B::constructor"<<endl;}
        void fun(){func();}
        //~B(){fund();}
        ~B(){cout<<"B::destructor"<<endl;}
};
class C:public B{
    public:
        C(){cout<<"C::constructor"<<endl;}
        void func(){cout<<"C::func"<<endl;}
        ~C(){cout<<"C::destructor"<<endl;}
        void fund(){cout<<"C::fund"<<endl;}
};
int main()
{C c;return 0;}