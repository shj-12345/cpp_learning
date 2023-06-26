// static2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
//静态成员变量：所有对象共享同一个值
//静态成员函数：只能访问静态成员变量
class CMyClass {
public:
   int a=10;
   static int m_i;
   static void get_param(){
    //cout<<"a="<<a<<endl;错误
    cout<<"m_i="<<m_i<<endl;
   }
};

int CMyClass::m_i = 0;
CMyClass myObject1;
CMyClass myObject2;

int main() {
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   myObject1.m_i = 1;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   myObject2.m_i = 2;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   CMyClass::m_i = 3;
   cout << myObject1.m_i << endl;
   cout << myObject2.m_i << endl;

   //static函数访问方式1：类名：：函数名
   CMyClass::get_param();
   //static函数访问方式2：类对象.函数名
   myObject1.get_param();
}