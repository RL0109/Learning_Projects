/* 
    Project 4-2
    Reverse a string in place
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

    char str[] = "This is a test";

    char *start, *end;

    int len;

    char t;

    cout << "Original: " << str << "\n";

    len = strlen(str);

    start = str;
    end = &str[len-1];

    while (start < end) {
        t = *start;
        *start = *end;
        *end = t;

        start++;
        end--;
    }

    cout << "Reveresed: " << str << "\n";
    return 0;

}

