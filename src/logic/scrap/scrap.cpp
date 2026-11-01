#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t responseData(
    char* data,
    size_t size,
    size_t count,
    void* output
) {
    size_t bytes = size * count;
    string* res = static_cast<string*>(output);
    res->append(data, bytes);

    return bytes;
}

int scrap() {
    CURL* curl = curl_easy_init();

    if(curl == nullptr){
        cerr << "Failed to initialize curl\n";
        return 1;
    }

    string url = "https://github.com/0alm/scraper";

    string res;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, responseData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);

    CURLcode result = curl_easy_perform(curl);

        if (result != CURLE_OK) {
        cerr << "Request failed: "
             << curl_easy_strerror(result) << '\n';
    } else {
        long statusCode = 0;

        curl_easy_getinfo(
            curl,
            CURLINFO_RESPONSE_CODE,
            &statusCode
        );

        cout << "HTTP Status: " << statusCode << '\n';
        cout << "Response:\n\n";
        cout << res << '\n';
    }
    curl_easy_cleanup(curl);

    return 0;
}