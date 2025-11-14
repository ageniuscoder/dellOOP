#include <bits/stdc++.h>
using namespace std;
class LibraryItem{
    protected:
    int id;
    string title;
    string author;
    public:
    LibraryItem(int id,string title,string author){
        this->id=id;
        this->title=title;
        this->author=author;
    }

    virtual double getLatefee(int days)=0;
    virtual void display()=0;

    int getId(){
        return id;
    }
    virtual ~LibraryItem(){}
};
class Book:public LibraryItem{
    int fee;
    public:
    Book(int id,string title,string author):LibraryItem(id,title,author){
        fee=2;
    }
    double getLatefee(int days){
        return fee*days;
    }
    void display(){
        cout << "[Book] ID: " << id
             << ", Title: " << title
             << ", Author: " << author << endl;
    }
};

class Magazine:public LibraryItem{
    int fee;
    public:
    Magazine(int id,string title,string author):LibraryItem(id,title,author){
        fee=1;
    }
    double getLatefee(int days){
        return fee*days;
    }
    void display(){
        cout << "[Magazine] ID: " << id
             << ", Title: " << title
             << ", Author: " << author << endl;
    }
};

class ResearchPaper:public LibraryItem{
    int fee;
    public:
    ResearchPaper(int id,string title,string author):LibraryItem(id,title,author){
        fee=5;
    }
    double getLatefee(int days){
        return fee*days;
    }
    void display(){
        cout << "[ResearchPaper] ID: " << id
             << ", Title: " << title
             << ", Author: " << author << endl;
    }
};

class Library{
    vector<shared_ptr<LibraryItem>> items;
    public:
    Library& operator +=(shared_ptr<LibraryItem> item){
        items.push_back(item);
        return *this;
    }

    Library & operator-=(int id){                     //key note iterator is not a pointer
        for(auto it=items.begin();it!=items.end();it++){
            if((*it)->getId()==id){            //so here i have to use (*it) it gives pointer
                items.erase(it);
                break;
            }
        }
        return *this;
    }
    friend ostream& operator <<(ostream &out,Library &b);
};

ostream& operator <<(ostream &out,Library &b){
    out << "\n===== Library Items =====\n";
    for(auto &item:b.items){
        item->display();
    }
    return out;
}
int main(){
    Library lib;
    lib+=make_shared<Book>(101, "C++ Primer", "Lippman");
    lib+=make_shared<Magazine>(201, "NatGeo", "John Doe");
    lib+=make_shared<ResearchPaper>(301, "AI Research", "Andrew Ng");

    cout<<lib;

    lib-=201;

    cout << "\nAfter Removing ID 201:\n";
    cout << lib;

}