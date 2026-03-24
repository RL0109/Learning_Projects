#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <curl/curl.h>
#include "config.h"

CURLcode callWeather(CURL* curlobj, std::string& cityName);

int main() {
	
	curl_global_init(CURL_GLOBAL_DEFAULT);
	CURL* curl = curl_easy_init();
	std::string city;

	std::cout << "Please pick city or town you want to see the weather for: ";
	std::getline (std::cin , city);



	callWeather(curl, city);

	curl_easy_cleanup(curl);
	curl_global_cleanup();
	system("pause");
	return 0;
}

CURLcode callWeather(CURL* curlobj, std::string& cityName) {
	std::cout << ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName +"&appid=" + API_KEY).c_str() << "\n";
	auto urlString = ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName +"&appid=" + API_KEY);
	std::cout << typeid(urlString).name() << "\n";
	curl_easy_setopt(curlobj, CURLOPT_URL, urlString.c_str());
	CURLcode result = curl_easy_perform(curlobj);

	if (result != CURLE_OK) {
		std::cout << "Error: " << curl_easy_strerror(result) << std::endl;
	} else {
		std::cout << "Success!" << std::endl;
	}
	return result;

}



//class WeatherData {
//	public:
//		WeatherData() : temperature(0), humidity(0), weatherConditions("") {}
//
//		void setTemperature(double temp) { temperature = temp;}
//		void setHumidity(double hum) { humidity = hum;}
//		void setWeatherConditions(const string& conditions) { weatherConditions = conditions; }
//
//		double getTemperature() const { return temperature; }
//		double getHumidity() const { return humidity; }
//		string getWeatherConditions() const { return weatherConditions; }
//
//	private:
//		dpibe
//
//};
