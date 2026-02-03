// Define + and = for ThreeD class

#include <iostream>
using namespace std;

class ThreeD {
    int x, y, z;
    public:
    ThreeD() {x = y = z= 0;}
    ThreeD(int i, int j, int k) {x = i, y = j, z = k;}

    ThreeD operator+(ThreeD op2); // op1 is implied
    ThreeD operator=(ThreeD op2);

    void show();
};

//Overload +
ThreeD ThreeD::operator+(ThreeD op2)
{
    ThreeD temp;

    temp.x = x + op2.x; // These are integer additions
    temp.y = y + op2.y; // and the + retains its original
    temp.z = z + op2.z; // meaning relative to them

    return temp;
}

//Overload assignment
ThreeD ThreeD::operator=(ThreeD op2)
{
    x = op2.x; // These are integer assignments
    y = op2.y; // and the = retains its original
    z = op2.z; // meaning relative to them
    return *this;
}

void ThreeD::show()
{
    cout << x << ", ";
    cout << y << ", ";
    cout << z << "\n";
}

int main()
{
    ThreeD a(1,2,3), b(10,10,10), c;

    cout << "Original value of a: ";
    a.show();
    cout << "Original value of b: ";
    b.show();

    cout << "\n";

    c = a+ b; // add a and b together
    cout << "Value of c after c = a + b: ";
    c.show();

    cout << "\n";

    c = a + b + c; // add a, b, and c together
    cout << "Value of c after c = a + b + c: ";
    c.show();

    cout << "\n";

    c + b = a; // demonstrate multiple assignment
    cout << "Value of c after c = b = a: ";
    c.show();
    cout << "Value of b after c = b = a: ";
    b.show();
    
    return 0;

}