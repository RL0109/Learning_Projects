#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <nlohmann/json.hpp>
#include <curl/curl.h>


class WeatherData {
    public: 
        std::string data;
        WeatherData(std::string result) : data(result) {}


        inline void print() {
            std::cout << data << "\n";
        }
};