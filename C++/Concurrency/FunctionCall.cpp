#include <iostream>

void call() {
    std::cout << "This function has been called." << "\n";
}


int main() {

    void (&g)() = call; 

    call();
    g();
}