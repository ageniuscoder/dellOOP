#include <iostream>
using namespace std;

class Shallow {
public:
    int* data;

    Shallow(int x) {
        data = new int(x);
    }

    // Default copy constructor → Shallow Copy
    // Shallow(const Shallow& other) = default;

    void show() {
        cout << "Value: " << *data 
             << " | Address: " << data << endl;
    }

    ~Shallow() {
        delete data;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1;   // SHALLOW COPY

    cout << "Before change:\n";
    obj1.show();
    obj2.show();

    // Changing obj2 affects obj1 also
    *obj2.data = 50;

    cout << "\nAfter changing obj2:\n";
    obj1.show();
    obj2.show();

    return 0;
}

// Before change:
// Value: 10 | Address: 0x55a...
// Value: 10 | Address: 0x55a...  (same pointer!)

// After changing obj2:
// Value: 50 | Address: 0x55a...
// Value: 50 | Address: 0x55a...





#include <iostream>
using namespace std;

class Deep {
public:
    int* data;

    Deep(int x) {
        data = new int(x);
    }

    // Deep copy constructor
    Deep(const Deep& other) {
        data = new int(*other.data);  // allocate new memory
    }

    void show() {
        cout << "Value: " << *data
             << " | Address: " << data << endl;
    }

    ~Deep() {
        delete data;
    }
};

int main() {
    Deep obj1(10);
    Deep obj2 = obj1;   // DEEP COPY

    cout << "Before change:\n";
    obj1.show();
    obj2.show();

    // Changing obj2 DOES NOT affect obj1
    *obj2.data = 50;

    cout << "\nAfter changing obj2:\n";
    obj1.show();
    obj2.show();

    return 0;
}

// Before change:
// Value: 10 | Address: 0x55a...
// Value: 10 | Address: 0x66b...  (different pointers!)

// After changing obj2:
// Value: 10 | Address: 0x55a...
// Value: 50 | Address: 0x66b...




// | Feature           | Shallow Copy                | Deep Copy                      |
// | ----------------- | --------------------------- | ------------------------------ |
// | Pointer Copied?   | ✔ Yes (same address)        | ❌ No (new memory)              |
// | Data Independent? | ❌ No                        | ✔ Yes                          |
// | Destructor Issue  | Double delete               | Safe                           |
// | Performance       | Faster                      | Slower                         |
// | When used?        | when object has no pointers | when object has dynamic memory |
