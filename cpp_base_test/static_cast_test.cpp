//静态强制类型转换
//目标类型 变量名=static_cast<目标类型>(变量)
#include <iostream>
using namespace std;
class A{
public:
    A(){cout<<"class A construtor"<<endl;}
    ~A(){cout<<"class A destrutor"<<endl;}
    void fun1(){cout<<"fun1()"<<endl;}
};
class B:public A{
public:
    B():A(){cout<<"class B construtor"<<endl;}
    ~B(){cout<<"class B destrutor"<<endl;}
    void fun2(){cout<<"fun2()"<<endl;}

};
class C{
public:
    C(A& a){A a_=a;cout<<"class C construtor"<<endl;}
    ~C(){cout<<"class C destrutor"<<endl;}
    void fun3(){cout<<"fun3()"<<endl;}
private:
    //A a_;
};
int main()
{
    //父类和子类的类型转换
    A a;
    B b;
    A* pa=static_cast<A*>(&b);
    B* pb=static_cast<B*>(&a);
    pa->fun1();
    //pa->fun2();报错：class A中没有fun2()
    pb->fun1();
    pb->fun2();

    //普通类之间的强制转换
    //类C包含类A的对象，且C的构造函数参数为类A的对象，才可将A转换为C
    C c(a);
    C c2=static_cast<C>(a);//正确:可以将A转化为C
    //C* pc=static_cast<C*>(&a);  //报错：不能将A*转换为C*
    return 0;
}