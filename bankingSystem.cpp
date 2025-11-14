#include <bits/stdc++.h>
using namespace std;
class Account{
    static int num;
    protected:
    string name;
    int balance;
    public:
    int accNo;
    Account(){
        num++;
    }
    void createAccount(string name,int balance){
        this->name=name;
        accNo=num;
        this->balance=balance;
        cout<<"Account Succesfully Created"<<accNo<<" for "<<name<<endl;
    }
    
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            cout<<amount<<" credited into account "<<accNo<<endl;
        }
    }
    
    void withdraw(int amount){
        if(amount<0){
            throw runtime_error("Invalid amount");
        }
        if(amount>balance){
            throw runtime_error("Insuffcient Balance");
        }
        balance-=amount;
        cout<<amount<<" debited from account "<<accNo<<endl;
    }
    
    void display(){
        cout << "Account Number: " << accNo << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    
    virtual void interest()=0;
    
};
int Account::num=1000;

class SavingsAccount:public Account{
    double interestRate;
    public:
    SavingsAccount(double rate=0.04):Account(){
        interestRate=rate;
    }    
    void interest(){
        double interest=balance*interestRate;
        balance+=interest;
        cout << "💰 Interest of " << interest << " added to Saving Account.\n";
    }
    
};

class CurrentAccount:public Account{
    double interestRate;
    public:
    CurrentAccount(double rate=0.02):Account(){
        interestRate=rate;
    }    
    void interest(){
        double interest=balance*interestRate;
        balance+=interest;
        cout << "💰 Interest of " << interest << " added to Current Account.\n";
    }
    
};

int main() {
    vector<Account*> accounts;

    cout << "🏦 Welcome to the Banking System\n";

    while (true) {
        cout << "\n-----------------------------\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Current Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Apply Interest to All Accounts\n";
        cout << "7. Exit\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        try {
            if (choice == 1) {
                string name;
                double amount;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                SavingsAccount* sa = new SavingsAccount();
                sa->createAccount(name, amount);
                accounts.push_back(sa);
            }
            else if (choice == 2) {
                string name;
                double amount;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                CurrentAccount* ca = new CurrentAccount();
                ca->createAccount(name, amount);
                accounts.push_back(ca);
            }
            else if (choice == 3) {
                int id; double amt;
                cout << "Enter account number: ";
                cin >> id;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                bool found = false;
                for (auto acc : accounts) {
                    if (acc->accNo == id) {
                        acc->deposit(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "❌ Account not found.\n";
            }
            else if (choice == 4) {
                int id; double amt;
                cout << "Enter account number: ";
                cin >> id;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                bool found = false;
                for (auto acc : accounts) {
                    if (acc->accNo == id) {
                        acc->withdraw(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "❌ Account not found.\n";
            }
            else if (choice == 5) {
                for (auto acc : accounts)
                    acc->display();
            }
            else if (choice == 6) {
                for (auto acc : accounts)
                    acc->interest();
            }
            else if (choice == 7) {
                cout << "👋 Exiting Banking System... Thank you!\n";
                break;
            }
            else {
                cout << "❌ Invalid choice. Try again.\n";
            }
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    // Clean up memory
    for (auto acc : accounts)
        delete acc;

    return 0;
}
