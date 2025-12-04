/* 
    Project 6-3
    Swaps two references
*/
#include <iostream>
int &min_swap(int& a, int& b);

int main() {
    int i = 7;
    int j = 17;
    int min;

    min = min_swap(i,j); 
    std::cout << min << "\n";

}

int &min_swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;

    if (a > b) {
        return b;
    } else {
        return a;
    }
    
}