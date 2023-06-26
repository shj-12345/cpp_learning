/*简单工厂模式：
优点：简单
缺点：不符合开闭原则，新增水果种类时需要修改factory内部函数
解决方法：工厂方法模式
*/
#include <string>
#include <iostream>
using namespace std;
class Fruit{
public:
    virtual void getFruit()=0;
};

class Banana:public Fruit{
public:
    virtual void getFruit() override{
        cout<<"I am banana"<<endl;
    }
};
class Apple:public Fruit{
public:
    virtual void getFruit() override{
        cout<<"I am apple"<<endl;
    }
};

class FruitFactory{
public:
    Fruit * creatFruit(string fruit_type)
    {
        if(fruit_type=="apple")
        {
            return new Apple;
        }
        else if(fruit_type=="banana")
        {
            return new Banana;
        }
        else
        {
            cout<<"不支持此类型"<<endl;
            return NULL;
        }
    }
};
int main()
{
    FruitFactory* f = new FruitFactory;

    Fruit* ft = NULL;
    //生产香蕉
    ft = f->creatFruit("banana");
    ft->getFruit();
    delete ft;
    //生产苹果
    ft = f->creatFruit("apple");
    ft->getFruit();
    delete ft;

    delete f;
    return 0;
}