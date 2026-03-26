#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using json = nlohmann::json;

class WeatherData {
    public: 
        std::string data;
        WeatherData(std::string result) : data(result) {}

        inline void print() {
            std::cout << data << "\n";
        }

        inline void readAsJSON() {
            json Doc{json::parse(data)};
            std::cout << Doc;
        }

        
};