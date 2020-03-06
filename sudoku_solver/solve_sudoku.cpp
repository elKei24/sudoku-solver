#include <iostream>
#include <vector>
#include "solve_sudoku.h"

bool solve(sudoku *s, int row_start, int col_start) {
    int size = s->getSize();

    // find next empty cell
    int row, col;
    for (row = row_start + col_start / size; row < size; row++) {
        for (col = col_start % size; col < size; col++) {
            if (!s->isSet(row, col)) goto ifHaveEmptyCell;
        }
        col_start = 0;
    }
    // if no empty cell left: done
    return true;

    ifHaveEmptyCell:
    auto legalEntries = s->legalEntries(row, col);
    for (entry checkVal: *legalEntries) {
        // test if checkVal leeds to a solution
        s->setEntry(row, col, checkVal);
        if (solve(s, row, col + 1)) {
            delete legalEntries;
            return true; // solution found
        }
    }
    // none of the legal entries led to a solution
    delete legalEntries;
    s->setEntry(row, col, EMPTY);
    return false;
}