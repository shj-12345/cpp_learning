/*map 内部结构：红黑树，按照键值大小对元素排序*/
/*unordered_map内部结构：哈希表，无序*/
/*set:内部结构平衡二叉树，按照元素大小有序排列*/
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main()
{
    std::cout<<"********************************"<<std::endl;
    {
        std::map<string,int> m1 = {{"A",100},{"B",200},{"C",300}};
        m1["a"] = 111;//插入方式1
        m1.insert(std::pair<string,int>("b",222));//插入方式2
        auto p = std::make_pair<string,int>("c",333);//插入方式3
        m1.insert(p);
        
        /*遍历元素*/
        for(auto iter = m1.begin();iter!= m1.end();iter++){
            std::cout<< iter->first << " :" << iter->second << std::endl;
        }

        /*查找元素*/
        auto iter = m1.find("a");
        if(iter!=m1.end()){
            std::cout<<"找到 a :";
            std::cout<< iter->first << " :" << iter->second << std::endl;
        }
        
        m1.erase(iter);//按照迭代器进行删除，时间复杂度为O(1)
        m1.erase("b");//按照键值进行删除,时间复杂度为O(logN)
        std::cout << m1.size() << std::endl;
        m1.clear();//清空map

    }

    std::cout<<"********************************"<<std::endl;
    {
        /*函数接口与有序map完全一致，只是内部存储结构不同*/
        std::unordered_map<string,int> m2;
    }
    
    std::cout<<"********************************"<<std::endl;
    {
        std::set<int> s1={5,4,3,2,1};
        for(auto iter = s1.begin();iter!= s1.end();iter++){
            std::cout<< *iter << std::endl;
        }
    }

    std::cout<<"********************************"<<std::endl;
    {
        class A{
        public:
            A(int i):i(i){
                std::cout<<"using A constructor"<<endl;
            }
            explicit A(const A& a){
                this->i = a.i;
                std::cout<<"using A copy constructor"<<endl;
            }
            A(A&& a){
                this->i = a.i;
                std::cout<<"using A move constructor"<<endl;
            }
            ~A(){
                std::cout<<"using A  destructor"<<endl;
            }
            int i;
        };

        std::vector<A> v;
        v.reserve(10);
        v.push_back(A(3));//需要构造临时对象，
        v.emplace_back(3);//无需构造临时对象，避免了临时对象内存的开辟和释放，节省时间，但是存在代码可读性差的缺点,容易出错，对代码效率要求较高时可以选择
    }

    return 0;
}