#include <iostream>
#include <string>
#include <curl/curl.h>

//ima take da
size_t WriteCallback(void* contents, size_t size, size_t numbe, std::string* userp) {
    userp->append((char*)contents, size * numbe);
    return size * numbe;
}

int main() {
    CURL* curl = curl_easy_init(); //pointer to startup up the curl
    std::string readBuffer;


    return 0;
}