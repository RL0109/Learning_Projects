// Operator overload using friend functions for integer + object and object + integer

#include <iostream>
using namespace std;

class ThreeD {
    int x, y, z; // 3-D coordinates

    public:
        ThreeD() {x = y = z = 0;}
        ThreeD(int i, int  j, int k) { x = i; y = j; z = k;}

        friend ThreeD operator+(ThreeD op1, int op2);
        friend ThreeD operator+(int op1, ThreeD op2);

        void show();
};

// This alllows ThreeD + int
ThreeD operator+(ThreeD op1, int op2)
{
    ThreeD temp;

    temp.x = op1.x + op2;
    temp.y = op1.y + op2;
    temp.z = op1.z + op2;

    return temp;
}

// This allows int + ThreeD
ThreeD operator+(int op1, ThreeD op2)
{
    ThreeD temp;

    temp.x = op1 + op2.x;
    temp.y = op1 + op2.y;
    temp.z = op1 + op2.z;

    return temp;
}

//Show X, Y, Z coordinates
void ThreeD::show()
{
    cout << x << ", ";
    cout << y << ", ";
    cout << z << "\n";

}

int main() 
{
    ThreeD a(1,2,3), b;

    cout << "Original value of a: ";
    a.show();

    cout <<"\n";

    b = a + 10; // object + integer
    cout << "Value of b after b = a + 10: ";
    b.show();

    cout << "\n";

    b = 10 + a; // integer + object
    cout << "Value of b after b = 10 + a: ";
    b.show();

    return 0;
}