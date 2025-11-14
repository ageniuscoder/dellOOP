//shopping portal with coupons
#include <bits/stdc++.h>
using namespace std;
class Product{
    int id;
    string name;
    double price;
    public:
    Product(int id,string name,double price){
        this->id=id;
        this->name=name;
        this->price=price;
    }
    double getPrice(){
        return price;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
};

class DiscountStrategy{
    public:
    virtual double apply(double price)=0;
    virtual ~DiscountStrategy(){}
};
class NoDiscount:public DiscountStrategy{
    public:
    double apply(double price){
        return price;
    }
};
class PercentageDiscount:public DiscountStrategy{
    int pct;
    public:
    PercentageDiscount(int p):pct(p){}
    double apply(double price){
        return price-(price*(pct/100.0));
    }
};
class FlatDiscount:public DiscountStrategy{
    double dis;
    public:
    FlatDiscount(double d){
        dis=d;
    }
    double apply(double price){
        return price-dis;
    }
};
class CartItem{
    Product product;
    int qty;
    shared_ptr<DiscountStrategy> strategy;
    public:
    CartItem(int q,Product &p,shared_ptr<DiscountStrategy> d):product(p),strategy(d){
        qty=q;
    }

    double getTotal(){
        double discounted=strategy->apply(product.getPrice());
        return discounted*qty;
    }

    Product getProduct(){
        return product;
    }

    void display() {
        cout << product.getName()
             << " | Qty: " << qty
             << " | Original: " << product.getPrice()
             << " | Final: " << strategy->apply(product.getPrice())
             << " | Total: " << getTotal()
             << endl;
    }

};

class Cart{
    vector<CartItem> items;
    public:
    void addItem(CartItem &c){
        items.push_back(c);
        cout<<c.getProduct().getName()<<" added succesfully"<<endl;
    }
    void removeItem(int id){
        for(auto it=items.begin();it!=items.end();it++){
            if((*it).getProduct().getId()==id){
                string name=(*it).getProduct().getName();
                items.erase(it);
                cout<<name<<" delelted from Cart"<<endl;
                break;
            }
        }
    }

    Cart operator+(Cart &c){
        Cart merged;
        merged.items=this->items;
        merged.items.insert(merged.items.end(),c.items.begin(),c.items.end());
        return merged;
    }

    friend ostream& operator<<(ostream& out, Cart& c);
};
ostream& operator<<(ostream &out,Cart &c){
    out << "\n===== FINAL BILL =====\n";
    double total=0;
    for(auto item:c.items){
        item.display();
        total+=item.getTotal();
    }
    out << "---------------------------\n";
    out << "Grand Total: " << total << "\n";

    return out;
}
int main(){
    Product p1(101, "Laptop", 50000);
    Product p2(102, "Shoes", 2500);
    Product p3(103, "Headphones", 1500);

    CartItem item1(2,p1,make_shared<PercentageDiscount>(20));
    CartItem item2(4,p2,make_shared<FlatDiscount>(50));
    CartItem item3(2,p3,make_shared<NoDiscount>());
    Cart c1,c2,c3;

    c1.addItem(item1);
    c1.addItem(item2);
    cout<<c1;
    c2.addItem(item3);
    cout<<c2;

    c3=c1+c2;
    cout<<c3;
}