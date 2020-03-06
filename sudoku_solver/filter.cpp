
#include "filter.h"

filter::filter(unsigned int filter) : mask(filter) {}

void filter::addEntry(entry e) {
    mask |= 1 << e;
}

void filter::clearEntry(entry e) {
    mask &= ~(1 << e);
}

bool filter::contains(entry e) {
    return mask & (1 << e);
}
