#include <iostream>
#include <map>
#include <chrono>

enum class Side {Buy, Sell};

struct Order {
    uint64_t Id;
    int quantity;
    long price;
    Side side;
    uint64_t time;

    Order(uint64_t id, int q, long p ) : Id(id), quantity(q), price(p) {
        time = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    }


};