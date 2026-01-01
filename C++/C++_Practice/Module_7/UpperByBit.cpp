#include <iostream>
#include <stdio.h>
using namespace std;


void showBinary(unsigned int u) 
{
    int t;

    for (t = 128; t > 0; t = t/2) 
    if( u & t) cout << "1 ";
    else cout << "0 ";

    cout << "\n";
}



int main() {

    char ch;
    char number;

    number = 223;

    showBinary(number);
for(int i = 0; i < 10; i++) {
    ch = 'a' + i;
    cout << ch;

    //This statement turns off the 6th bit.
    ch = ch & 223; // ch is now uppercase
    
    cout << ch << " ";
}

cout << "\n";

    return 0;
}