#include <algorithm>
#include <iostream>
#include "sudoku.h"
#include "sudoku_solver/filter.h"

int sudoku::getSize() {
    return block_size * block_size;
}

int sudoku::getBlockSize() {
    return block_size;
}

bool sudoku::isSet(int row, int col) {
    return getEntry(row, col) != EMPTY;
}

entry sudoku::getEntry(int row, int col) {
    return entries[row * getSize() + col];
}

void sudoku::setEntry(int row, int col, entry value) {
    clearFilterEntry(getEntry(row, col), row, col);
    entries[row * getSize() + col] = value;
    addFilterEntry(value, row, col);
}

sudoku::sudoku(int block_size) : block_size(block_size) {
    int size = block_size * block_size;

    entries = new entry[size * size];
    std::fill(entries, &entries[size * size - 1], EMPTY);

    rowFilters = new filter[size];
    std::fill(rowFilters, &rowFilters[size - 1], filter());
    colFilters = new filter[size];
    std::fill(colFilters, &colFilters[size - 1], filter());
    blockFilters = new filter[size];
    std::fill(blockFilters, &blockFilters[size - 1], filter());
}

sudoku::~sudoku() {
    delete [] entries;
    delete [] rowFilters;
    delete [] colFilters;
    delete [] blockFilters;
}

void sudoku::print() {
    for (int i = 0; i <= getSize(); i++) {
        // print block row separators
        if (i % getBlockSize() == 0) std::cout << "+-------+-------+-------+" << std::endl;
        if (i == getSize()) break;

        // print block row
        for (int j = 0; j < getSize(); j++) {
            //print block column separators
            if (j % getBlockSize() == 0) std::cout << "| ";

            // print cell value
            entry value = getEntry(i, j);
            if (value == EMPTY) {
                std::cout << " ";
            } else {
                std::cout << (int) value;
            }
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
}

filter *sudoku::findBlockFilter(int row, int col) {
    int block_row = row / block_size;
    int block_col = col / block_size;
    return &blockFilters[block_row * block_size + block_col];
}

void sudoku::addFilterEntry(entry entry, int row, int col) {
    rowFilters[row].addEntry(entry);
    colFilters[col].addEntry(entry);
    findBlockFilter(row, col)->addEntry(entry);
}

void sudoku::clearFilterEntry(entry entry, int row, int col) {
    rowFilters[row].clearEntry(entry);
    colFilters[col].clearEntry(entry);
    findBlockFilter(row, col)->clearEntry(entry);
}

std::vector<entry> *sudoku::legalEntries(int row, int col) {
    filter rowFilter = rowFilters[row];
    filter colFilter = colFilters[col];
    filter blockFilter = *findBlockFilter(row, col);
    filter combinedFilter = rowFilter | colFilter | blockFilter;
    auto *legalEntries = new std::vector<entry>();

    for (entry checkEntry = 1; checkEntry <= getSize(); checkEntry++) {
        if (!combinedFilter.contains(checkEntry)) {
            legalEntries->push_back(checkEntry);
        }
    }

    return legalEntries;
}
