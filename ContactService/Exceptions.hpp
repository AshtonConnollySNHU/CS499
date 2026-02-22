#include <stdexcept>
#include <string>
using namespace std;

class validationError : public runtime_error {
public:
    explicit validationError(const string& message)
        : runtime_error(message) {}
};


class NotFoundError : public runtime_error {
    public:
    explicit NotFoundError(const string& message)
        : runtime_error(message) {}
};