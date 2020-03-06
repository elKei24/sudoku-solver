#ifndef CPP_TEST_SUDOKU_H
#define CPP_TEST_SUDOKU_H

#include <vector>
#include "sudoku_solver/filter.h"
#include "entry.h"

class sudoku {
    int block_size;
    entry *entries;
    filter *rowFilters;
    filter *colFilters;
    filter *blockFilters;
    void addFilterEntry(entry entry, int row, int col);
    void clearFilterEntry(entry entry, int row, int col);
    filter *findBlockFilter(int row, int col);
public:
    int getSize();

    bool isSet(int row, int col);

    entry getEntry(int row, int col);

    void setEntry(int row, int col, entry value);

    explicit sudoku(int block_size);

    virtual ~sudoku();

    void print();

    int getBlockSize();

    std::vector<entry> *legalEntries(int row, int col);
};


#endif //CPP_TEST_SUDOKU_H
