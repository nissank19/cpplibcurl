#include <iostream>
#include <curl/curl.h>

int main() {
    CURL *curl = curl_easy_init();
    if(curl) {
        std::cout << "Success! The 'Mapping' to Curl is complete." << std::endl;
        curl_easy_cleanup(curl);
    } else {
        std::cout << "Failed to initialize. Check the library path." << std::endl;
    }
    return 0;
}