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

    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
};
class CartItem{
    Product product;
    int quantity;
    public:
    CartItem(Product p,int quantity):product(p){
        this->quantity=quantity;
    }
    int getQuantity(){
        return quantity;
    }
    Product getProduct(){
        return product;
    }
    double totalAmount(){
        return product.getPrice()*quantity;
    }
    void addQuantity(int a){
        quantity+=a;
    }
};
class Cart{
    vector<CartItem> items;
    double tax;
    public:
    Cart(double t=0.05){
        tax=t;
    }
    void display(){
        if(items.size()==0) cout<<"Cart is Empty"<<endl;
        for(int i = 0; i < items.size(); i++){
            cout << "Name: " << items[i].getProduct().getName()
                << " Price: " << items[i].getProduct().getPrice()
                << " Quantity: " << items[i].getQuantity() 
                << " Total Amount: " << items[i].totalAmount() << endl;
        }
    }
    void addProduct(CartItem &c){
        bool found=false;
        for(auto &item:items){
            if(c.getProduct().getId()==item.getProduct().getId()){
                item.addQuantity(c.getQuantity());
                found=true;
                cout<<c.getProduct().getName()<<" already present and It,s quantity is updated"<<endl;
                break;
            }
        }
        if(!found){
            items.push_back(c);
            cout<<c.getProduct().getName()<<" added to the cart"<<endl;
        }
    }

    void removeProduct(int id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getProduct().getId() == id) {
                string name = it->getProduct().getName(); 
                items.erase(it); 
                
                cout << name << " removed from the cart" << endl;
                return; 
            }
        }
        cout << "Item is not present in the Cart" << endl;
    }

    // void removeProduct(int id) {
    //     auto initial_size = items.size();

    //     // std::erase_if returns the number of elements removed
    //     size_t removed_count = std::erase_if(items, [id](const CartItem& item) {
    //         return item.getProduct().getId() == id;
    //     });

    //     if (removed_count > 0) {
    //         cout << "Product with ID " << id << " removed from the cart." << endl;
    //     } else {
    //         cout << "Item is not present in the Cart" << endl;
    //     }
    // }

    void totalBill(){
        double total=0;
        for(auto item:items){
            total+=item.totalAmount();
        }
        double intrest=total*tax;
        cout<<"Total Bill for the Cart is: "<<total+intrest<<endl;
    }


};
int main(){
    Product p1(2,"apple",50);
    Product p2(3,"mango",20);
    Product p3(6,"banana",10);
    CartItem c1(p1,3);
    CartItem c2(p2,4);
    CartItem c3(p3,5);
    CartItem c4(p1,5);

    Cart cart;

    cart.addProduct(c1);
    cart.addProduct(c2);
    cart.addProduct(c3);
    cart.addProduct(c4);

    cart.display();

    cart.totalBill();

    cart.removeProduct(2);

    cart.display();

    cart.totalBill();



}