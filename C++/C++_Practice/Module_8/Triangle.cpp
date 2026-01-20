/* 
    Project 8-3 
    Using classes to find the hypotenuse of a triangle
*/
#include <iostream>
#include <cmath>

class Triangle 
{
    public: 
        float base;
        float height;

        Triangle(float b, float h) {
            base = b;
            height = h;
        }

        float hypot() {
            return std::sqrt((base * base ) + (height * height ));
        }

        float area() 
        {
            return (base * height) / 2;
        }

};


int main() 
{

    Triangle t1(4.0f,5.0f);

    std::cout << "Hypotenuse of triangle 1 is: " << t1.hypot() << "\n";

    std::cout << "Area of triangle 1 is: " << t1.area() << "\n";



}