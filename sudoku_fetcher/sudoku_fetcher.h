
#ifndef CPP_TEST_SUDOKU_FETCHER_H
#define CPP_TEST_SUDOKU_FETCHER_H

#include <curl/curl.h>
#include "../sudoku.h"
#include <exception>
using namespace std;

sudoku *fetchSudoku(unsigned char size, unsigned char level);

#endif //CPP_TEST_SUDOKU_FETCHER_H
