#include <iostream>
#include <cmath>
/*
 Project 2-2
*/

using namespace std;

int main() {
    bool q, p;
    p = true;
    q = true;



    
    cout << p << " XOR " << q << " is " << 
    ( ( p || q ) && !(p&&q)) << "\n";

    p = false;
    q = true;

    cout << p << " XOR " << q << " is " << 
    ( ( p || q ) && !(p&&q)) << "\n";

    p = true;
    q = false;

    cout << p << " XOR " << q << " is " << 
    ( ( p || q ) && !(p&&q)) << "\n";

    p = false;
    q= false;

    cout << p << " XOR " << q << " is " << 
    ( ( p || q ) && !(p&&q)) << "\n";

    return 0;
}
