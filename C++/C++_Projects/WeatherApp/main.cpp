#include "Weather.h"
#include <string>
#include "config.h"
#include <string.h>
#include <stdlib.h>

struct memory {
	char* response;
	size_t size;
};





std::string callWeather(CURL* curlobj, std::string& cityName);
static size_t write_callback(char* data, size_t size, size_t nmemb, void *clientp);


int main() {
	
	
	curl_global_init(CURL_GLOBAL_DEFAULT);
	CURL* curl = curl_easy_init();
	std::string city;

	std::cout << "Please pick city or town you want to see the weather for: ";
	std::getline (std::cin , city);

	std::string weatherData = callWeather(curl, city);
	WeatherData wD1(weatherData);
	wD1.print();



	curl_easy_cleanup(curl);
	curl_global_cleanup();
	system("pause");
	return 0;
}

static size_t write_callback(char *data, size_t size, size_t nmemb, void *clientp)
{
  size_t realsize = nmemb;
  struct memory *mem = (struct memory *)clientp;
 
  char *ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
  if(!ptr)
    return 0;  /* out of memory */
 
  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;
 
  return realsize;
}


std::string callWeather(CURL* curlobj, std::string& cityName) {
	struct memory chunk = { 0 };
	auto urlString = ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName +"&appid=" + API_KEY);
	curl_easy_setopt(curlobj, CURLOPT_URL, urlString.c_str());
	curl_easy_setopt(curlobj, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curlobj, CURLOPT_WRITEDATA, (void *)&chunk);
	CURLcode result = curl_easy_perform(curlobj);
	if (result != CURLE_OK) {
		std::cout << "Error: " << curl_easy_strerror(result) << std::endl;
	} else {
		std::cout << "Success!" << std::endl;
	}
	free(chunk.response);

	return std::string(chunk.response, chunk.size);

}

