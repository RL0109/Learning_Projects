#include <iostream>
#include <vector>

float earthToMoon (float w) {
    return w * .17;
}

int main () {

    for (int i = 0; i != 100; i++) {
        if (i % 25 == 0) {
            std::cout << earthToMoon(i) << std::endl;
        } else {
            std::cout << earthToMoon(i) << " ";
        }
    }

    return 0;
}