#include <bits/stdc++.h>
using namespace std;
class Rational{
    int num;
    int den;
    void simplify(){
        if(den<0){
            num=-num;
            den=-den;
        }
        int g=gcd(abs(num),abs(den));
        if(g!=0){
            num=num/g;
            den=den/g;
        }
    }
    public:
    Rational(int n=0,int d=1){
        if(d==0){
            cerr<<"Invalid Raional Number"<<endl;
            exit(1);
        }
        num=n;
        den=d;
        simplify();
    }

    Rational operator +(const Rational &r) {
        int a=num*r.den+den*r.num;
        int b=den*r.den;
        return Rational(a,b);
    }

    Rational operator -(const Rational &r) {
        int a=num*r.den-den*r.num;
        int b=den*r.den;
        return Rational(a,b);
    }

    Rational operator *(const Rational &r) {
        int a=num*r.num;
        int b=den*r.den;
        return Rational(a,b);
    }

    Rational operator /(const Rational &r) {
        if(r.num==0){
            cerr<<"Can,t be divided"<<endl;
            exit(1);
        }
        int a=num*r.den;
        int b=den*r.num;
        return Rational(a,b);
    }

    bool operator ==(const Rational &r) {
        return (num==r.num && den==r.den);
    }

    bool operator !=(const Rational &r) {
        return !(*this==r);
    }

    
    friend ostream& operator<<(ostream & out,const Rational &r);

};

ostream& operator<<(ostream & out,const Rational &r){
    if(r.den==1){
        out<<r.num<<endl;
    }else
       out<<r.num<<"/"<<r.den<<endl;
    return out;
}
int main(){
    Rational r1(2, 3);
    Rational r2(4, 5);

    cout << "Rational 1: " << r1 << endl;
    cout << "Rational 2: " << r2 << endl;

    cout << "\nAddition: " << r1 + r2 << endl;
    cout << "Subtraction: " << r1 - r2 << endl;
    cout << "Multiplication: " << r1 * r2 << endl;
    cout << "Division: " << r1 / r2 << endl;

    Rational r3(4, 6); // simplifies to 2/3
    cout << "\nRational 3: " << r3 << endl;

    cout << "\nEquality (r1 == r3)? " << (r1 == r3 ? "True" : "False") << endl;
    cout << "Inequality (r1 != r2)? " << (r1 != r2 ? "True" : "False") << endl;

    return 0;
}