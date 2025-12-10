#include <bits/stdc++.h>  //safe for singlethread only
using namespace std;
class Singleton{  //way to create a class which create only single object
    private:
    static Singleton* s;
    Singleton(){
        cout<<"New object is created"<<endl;
    }
    public:
    static Singleton* getInstance(){
        if(s==nullptr){
            s=new Singleton();
        }
        return s;
    }
};
Singleton* Singleton::s=nullptr;
int main(){
    Singleton* obj1=Singleton::getInstance();
    Singleton* obj2=Singleton::getInstance();

    cout<<(obj1==obj2);


}