
#ifndef SUDOKU_SOLVER_CURL_EXCEPTION_H
#define SUDOKU_SOLVER_CURL_EXCEPTION_H

#include <exception>
using namespace std;

class CurlException: public exception {
private:
    const char* reason;
public:
    [[nodiscard]] const char* what() const noexcept override {
        return reason;
    }

    explicit CurlException(const char *reason) {
        this->reason = reason;
    }
};


#endif //SUDOKU_SOLVER_CURL_EXCEPTION_H
