/*
    Project 4-5
    Checks for uppercase characters
*/

#include <iostream>
#include <cstring>

using std::cout; using std::cin;

int main () {

    char str[80] = "This is a String. How am I?";

    char *p = str;

    int caseCount = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(p[i])) {
            caseCount++;
        }
    }

    cout << "Amount of cases in string: " << caseCount;

 



    return 0;
}