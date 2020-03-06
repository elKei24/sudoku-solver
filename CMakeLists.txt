cmake_minimum_required(VERSION 3.15)
project(sudoku_solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku_solver main.cpp sudoku.cpp sudoku.h sudoku_fetcher/sudoku_fetcher.cpp sudoku_fetcher/sudoku_fetcher.h sudoku_fetcher/curl_exception.cpp sudoku_fetcher/curl_exception.h sudoku_fetcher/curl_reader.cpp sudoku_fetcher/curl_reader.h sudoku_solver/solve_sudoku.cpp sudoku_solver/solve_sudoku.h sudoku_solver/filter.cpp sudoku_solver/filter.h entry.h)
target_link_libraries(sudoku_solver curl jsoncpp)