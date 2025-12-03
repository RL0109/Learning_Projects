#include <iostream>
#include <cstring>

int main() {

    short int hightemps[31];
    int *p;
    int arr[] = {1, 1, 5, 5, 7, 7, 8, 9, 10, 11};
    p = arr;
    for (int i = 0; i < 10 ; i++) {
        for (int j = 0; j < 10; j++) {
            if (*(p + i) == *(p + j)) {
                std::cout << "Match found: " << p[i] << " & " << p[j] << std::endl;
            }
        }
    }


    return 0;
}