
#include "../sudoku.h"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "sudoku_fetcher.h"
#include "curl_exception.h"
#include "curl_reader.h"
#include <jsoncpp/json/json.h>
#include <cmath>

using namespace std;

static const char SUDOKU_GENERATOR_URL[] = "http://www.cs.utep.edu/cheon/ws/sudoku/new/?level=%u&size=%u";

sudoku *buildSudoku(string sudoku_info);

sudoku *buildSudoku(Json::Value json_root);

sudoku *fetchSudoku(unsigned char size, unsigned char level) {
    char url[sizeof(SUDOKU_GENERATOR_URL) / sizeof(*SUDOKU_GENERATOR_URL) + 10];
    sprintf(url, SUDOKU_GENERATOR_URL, level, size);
    string sudoku_info = CurlReader().readUrl(url);
    return buildSudoku(sudoku_info);
}

sudoku *buildSudoku(string sudoku_info) {
    Json::Reader reader;
    Json::Value root;
    reader.parse(sudoku_info, root);
    return buildSudoku(root);
}

sudoku *buildSudoku(Json::Value root) {
    int size = stoi(root["size"].asCString());
    int block_size = sqrt(size);
    auto *s = new sudoku(block_size);

    auto squares = root["squares"];
    for (const auto& square : squares) {
        int value = square["value"].asInt();
        int x = square["x"].asInt();
        int y = square["y"].asInt();
        s->setEntry(x, y, value);
    }

    return s;
}
