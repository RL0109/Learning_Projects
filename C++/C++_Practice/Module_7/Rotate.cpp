/*
    Project 7-1

    Lef tand right rotate functions for byte values.
*/
#include <iostream>
using namespace std;

unsigned char lrotate(unsigned char val, int n) 
{
    unsigned int t;

    t = val;

    for (int i = 0; i < n; i++) 
    {
        t = t << 1;
        if (t & 256 )
        t= t | 1; 
    }

    return t;
}

unsigned char rrotate(unsigned char val, int n) 
{
    unsigned int t;

    t = val;

    t = t << 8;

    for (int i =0; i < n; i++) 
    {
        t = t >> 1;
        if (t & 128)
            t = t | 32768;
    }
    t =t >> 8;
    return t;
}

void showBinary(unsigned int u) 
{
    int t;

    for (t = 128; t > 0; t = t/2) 
    {
        if (u & t) cout << "1 ";
        else cout << "0 ";

        
    }
    cout << "\n";
}

int main () {

    char ch = 32;
    showBinary(ch);
    ch = lrotate(ch , 10);
    ch = rrotate(ch , 14);
    showBinary(ch);


}