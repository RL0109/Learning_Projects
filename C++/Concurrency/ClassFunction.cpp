#include <iostream>
#include <thread>

class functionClass {

    public:

        void additionalFunc() {
            std::cout << "This function is added to the operator function." << "\n";
        }


        void operator()() {
            additionalFunc();
            std::cout << "This class behaves as a function." << std::endl;
        }


};


int main() {

    functionClass fc;

    fc();

    std::thread my_thread(fc);
    my_thread.join();

}