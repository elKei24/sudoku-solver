#include <iostream>
#include "sudoku_fetcher/sudoku_fetcher.h"
#include "sudoku_solver/solve_sudoku.h"

#include <chrono>

int main() {
    // fetch a sudoku and display it
    auto sudoku = fetchSudoku(9, 3);
    sudoku->print();

    //solve it
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool solvable = solve(sudoku);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // print solution
    if (solvable) {
        sudoku->print();
    } else {
        cout << "This sudoku has no solution." << endl;
    }

    // print duration
    cout << "Solving took " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " µs." << endl;

    delete sudoku;
    return 0;
}
