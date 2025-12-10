#include <bits/stdc++.h>
using namespace std;             
class Singleton{  //way to create a class which create only single object     //safe for multi threading using mutex
    private:
    static Singleton* s;
    static mutex mtx;
    Singleton(){
        cout<<"New object is created"<<endl;
    }
    public:
    // static Singleton* getInstance(){ //not optimal
    //     lock_guard<mutex> lock(mtx);  //lock for thread safety
    //     if(s==nullptr){
    //         s=new Singleton();
    //     }
    //     return s;
    // }

    static Singleton* getInstance(){ //optimal way
        if(s==nullptr){
            lock_guard<mutex> lock(mtx);  //lock for thread safety
            if(s==nullptr){
                s=new Singleton();
            }
        }
        return s;
    }
};
Singleton* Singleton::s=nullptr;
mutex Singleton::mtx;
int main(){
    Singleton* obj1=Singleton::getInstance();
    Singleton* obj2=Singleton::getInstance();

    cout<<(obj1==obj2);


}