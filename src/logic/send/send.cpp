#include <iostream>
#include <string>
#include <curl/curl.h>
#include "../../../config/config.h"

using namespace std;

string file_Path;

void Send_telegram (string file_Path) {
    cout << "file path " << file_Path;

    string url = config::api + config::BotToken + config::method_Send;
    // cout << "[+] the url result :" << url;

    CURL* curl = curl_easy_init();
    curl_mime* mime = curl_mime_init(curl);
    curl_mimepart* chat = curl_mime_addpart(mime);

    curl_mime_name(chat, "chat_id");

    curl_mime_data(
        chat,
        config::chatID.c_str(),
        CURL_ZERO_TERMINATED
    );

    curl_mimepart* document = curl_mime_addpart(mime);
    curl_mime_name(document, "document");

    curl_mime_filedata(document, file_Path.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

    // cout << "[+] im here";

    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
    cerr << "[-] Error: " << curl_easy_strerror(result) << '\n';
    } else {
        cout << "[+] Request sent successfully!\n";
    }

    // cout << "[+] result :" << result;


    curl_mime_free(mime);
    curl_easy_cleanup(curl);
}

int main() {
    file_Path = "/Users/smk/Desktop/workspace-projects/scaper/test/file.txt";
    
    Send_telegram(file_Path);

    // cout << "all done";

    return 0;
}
