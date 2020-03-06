
#include "curl_reader.h"
#include "curl_exception.h"

CurlReader::CurlReader() {
    curl = curl_easy_init();
    if (!curl) throw CurlException("Curl handle failed");
}

CurlReader::~CurlReader() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
}

string CurlReader::readUrl(const char *url) {
    string buffer;
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    CURLcode res = curl_easy_perform(curl);
    return buffer;
}

size_t CurlReader::writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}
