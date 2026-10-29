#include <iostream>
#include <string>
#include <curl/curl.h>
#include "../../../config/config.h"

using namespace std;

string file_Path;

void Send_telegram (string file_Path) {
    cout << "file path " << file_Path;
    // CURL* curl = curl_easy_init();
    string url = config::api + config::BotToken + config::method_Send;
    cout << "[+] the url result :" << url;
    // curl_mime* mime = curl_mime_init(curl);
}

int main() {
    file_Path = "path";
    Send_telegram(file_Path);

    return 0;
}
