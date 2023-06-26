#include <memory>
#include <iostream>
using namespace std;
class B;
class A{
public:
    A(int num):num_(num){cout<<"A constructor"<<endl;}
    ~A(){cout<<"A destructor"<<endl;}
    void print_num(){cout<<"num_="<<num_<<endl;}
    // shared_ptr<B> ptrA_B;//无法释放，会陷入死循环
    weak_ptr<B> ptrA_B;
private:
    int num_;
};
class B{
public:
    B(int num):num_(num){cout<<"B constructor"<<endl;}
    ~B(){cout<<"B destructor"<<endl;}
    void print_num(){cout<<"num_="<<num_<<endl;}
    //shared_ptr<A> ptrB_A;//无法释放，会陷入死循环
    weak_ptr<A> ptrB_A;
private:
    int num_;
};
int main()
{
    //weak_ptr的特性：
    //1.weak_ptr只是访问内存，当其计数器-1到0时，并不会释放内存，shared_ptr会释放内存
    //2.可以将shared_ptr赋值给weak_ptr，反之会报错
    //3.weak_ptr无法解引用 
    shared_ptr<A> ptr_a=make_shared<A>(10);
    shared_ptr<B> ptr_b=make_shared<B>(20);
    ptr_a->ptrA_B=ptr_b;
    ptr_b->ptrB_A=ptr_a;
    //B b = *(ptr_a->ptrA_B);//报错：weak_ptr无法解引用
    //(ptr_a->ptrA_B)->print_num(); //报错：weak_ptr无法通过 ->访问成员变量和函数
    weak_ptr<A> ptr_a2=make_shared<A>(10);
    //ptr_a2->print_num();//报错：operator -> or ->* applied to "std::weak_ptr<A>" instead of to a pointer typeC/C++(3364）
    shared_ptr<A> ptr_a3 = ptr_a2.lock();//返回shared_ptr
    ptr_a3->print_num();//正确

    return 0;
}