#include <iostream>
using namespace std;


void showBinary(unsigned int u) 
{
    int t;

    for (t = 128; t > 0; t = t/2) 
    if( u & t) cout << "1 ";
    else cout << "0 ";

    cout << "\n";
}

int main() 
{
    char ch;
    showBinary(32);
    for( int i = 0; i < 10; i++) {
        ch = 'A' + i;
        cout << ch;

        //This satement turns on the 6th bit
        ch = ch | 32; //ch is now lowercase

        cout << ch << " ";
    }

    cout << "\n";

    return 0;
}