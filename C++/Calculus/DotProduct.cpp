#include <iostream>
#include <vector>
#include <numeric>

int main () {

    std::vector<float> p1 {1.0f, 0.0};
    std::vector<float> p2 {0.0f, 1.0f};
    if (std::inner_product(p1.begin(), p1.end(), p2.begin(), 0) == 0) {
        std::cout << "Vectors are perpendicular!" << "\n";
    }


    std::vector<float> v1 {10.1f, 5.4f, 7.3f};
    std::vector<float> v2 {15.2f, 8.06f, 4.7f};
    float result = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.0f);

    std::cout << result << "\n";


    return 0;
}