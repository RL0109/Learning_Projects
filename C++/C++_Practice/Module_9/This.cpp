// Practice use of This
#include <iostream>
using namespace std;


class T {
    int i, j;
    public:
    int sum() {
        return this-> i + this-> j;
    }

    T (int a, int b)
    {
        i = a;
        j = b;
    }
};

main()
{
    T ob(4,5);

    cout << ob.sum() << "\n";


}