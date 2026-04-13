#include <iostream>
#include <thread>

class functionClass {

    public:

        void additionalFunc() {
            std::cout << "This function is added to the operator function." << "\n";
        }


        void operator()() {
            additionalFunc();
            std::cout << "This class behaves as a function." << "\n";
        }


};

void call() {
    std::cout << "This is a print statement from a function." << "\n";
}


int main() {
    std::thread func_thread{call};
    func_thread.join();

    std::thread lambda_thread([]{call();});
    lambda_thread.join();

    functionClass fc;

    fc();

    std::thread class_thread(fc);
    class_thread.join();

}