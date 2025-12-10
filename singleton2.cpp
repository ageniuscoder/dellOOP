#include <bits/stdc++.h>
using namespace std;             
class Singleton{  //way to create a class which create only single object     //safe for multi threading using mutex  //eager initialization
    private:
    static Singleton* s;
    Singleton(){
        cout<<"New object is created"<<endl;
    }
    public:

    static Singleton* getInstance(){ 
        return s;
    }
};
Singleton* Singleton::s=new Singleton();

int main(){
    Singleton* obj1=Singleton::getInstance();
    Singleton* obj2=Singleton::getInstance();

    cout<<(obj1==obj2);


}