#include <iostream>
#include <string>
#include <curl/curl.h>

//ima take da
size_t WriteCallback(void* contents, size_t size, size_t numbe, std::string* userp) {
    userp->append((char*)contents, size * numbe);
    return size * numbe;
}
//https://api.binance.com

int main() {
    CURL* curl = curl_easy_init(); //pointer to startup up the curl
    std::string readBuffer;
    CURLcode res;
    if (curl==nullptr) {
        std::cout << "curl_easy_init failed" << std::endl;
        return -1;
    }
    curl_easy_setopt(curl,CURLOPT_URL,"https://api-gcp.binance.com/api/v3/aggTrades?symbol=BNBETH");
   // curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
    //curl_easy_setopt(curl,CURLOPT_USERAGENT,"yeso");
    curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,0L);
    curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0L);
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res=curl_easy_perform( curl);
    if (res!=CURLE_OK) {
        std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        return -1;
    }
    curl_easy_cleanup(curl);
    std::cout << readBuffer << std::endl;



    return 0;
}