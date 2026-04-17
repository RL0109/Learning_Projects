#include <iostream>
#include <thread>
#include <chrono>

class thread_guard {

    std::thread& t;
    public:
        explicit thread_guard(std::thread& t_) :
            t(t_) {}
        ~thread_guard()
        {
            if (t.joinable()) {
                t.join();
            }
        }
        thread_guard(thread_guard const&) =delete;
        thread_guard& operator=(thread_guard const&) =delete;


};


void task() {
    std::cout << "This task is running." << "\n";

    const char frames[] = {'\\','|','/' , '-'};

    for (int i = 0; i < 20; i++) {
        std::cout << frames [i%4] << "\b" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


    std::cout << "task complete!" << "\n";
}


int main() {
    std::thread t1(task);
    thread_guard guard(t1);


    if (t1.joinable()) {
        t1.join();
    }


}