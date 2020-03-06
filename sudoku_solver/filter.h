
#ifndef SUDOKU_SOLVER_FILTER_H
#define SUDOKU_SOLVER_FILTER_H

#include "../entry.h"

class filter {
    unsigned int mask;
public:
    void addEntry(entry e);
    void clearEntry(entry e);
    bool contains(entry e);

    filter(unsigned int filter = 0);

    inline filter operator |(filter b) {
        return filter(mask | b.mask);
    }

    inline filter operator &(filter b) {
        return filter(mask & b.mask);
    }
};


#endif //SUDOKU_SOLVER_FILTER_H
