#include <bits/stdc++.h>
using namespace std;

class Complex {
    double real;
    double img;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        img = i;
    }

    // Operator overloading
    Complex operator +(const Complex &c) const {
        return Complex(real + c.real, img + c.img);
    }

    Complex operator -(const Complex &c) const {
        return Complex(real - c.real, img - c.img);
    }

    Complex operator *(const Complex &c) const {
        return Complex(real * c.real - img * c.img, real * c.img + img * c.real);
    }

    bool operator ==(const Complex &c) const {
        return (real == c.real && img == c.img);
    }

    // Prefix ++
    Complex& operator ++() {
        ++real;
        ++img;
        return *this;
    }

    // Postfix ++
    Complex operator ++(int) {  // <-- fixed here
        Complex temp = *this;
        real++;
        img++;
        return temp;
    }

    // Friend function for output
    friend ostream& operator <<(ostream &output, const Complex &c);
};

// Overload << operator
ostream& operator <<(ostream &output, const Complex &c) {
    if (c.img >= 0)
        output << c.real << " + " << c.img << "i";
    else
        output << c.real << " - " << -c.img << "i";
    return output;
}

// Main function
int main() {
    Complex c1(4, 5);
    Complex c2(8, 9);

    Complex c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    Complex c4 = c1 - c2;
    cout << "Subtraction: " << c4 << endl;

    Complex c5 = c1 * c2;
    cout << "Multiplication: " << c5 << endl;

    Complex c6(4, 5);
    cout << "Equality (c1 == c6): " << (c1 == c6 ? "True" : "False") << endl;

    cout << "Postfix (c1++): " << c1++ << endl;  // prints old value
    cout << "After Postfix: " << c1 << endl;     // now incremented
    cout << "Prefix (++c1): " << ++c1 << endl;   // increments first

    return 0;
}
