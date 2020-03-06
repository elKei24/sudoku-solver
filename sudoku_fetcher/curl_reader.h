
#ifndef SUDOKU_SOLVER_CURL_READER_H
#define SUDOKU_SOLVER_CURL_READER_H

#include <curl/curl.h>
#include "../sudoku.h"
#include <exception>
#include <string>

using namespace std;

class CurlReader {
    CURL *curl;
    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
public:
    CurlReader();
    virtual ~CurlReader();
    string readUrl(const char* url);
};


#endif //SUDOKU_SOLVER_CURL_READER_H
