#include <iostream>
#include <sstream>

int main() {
    std::ostringstream stream;

    stream << "This is some text to redirect to a string stream." << std::endl;

    std::string output = stream.str();

    std::cout << "The output is: " << output << std::endl;

    return 0;
}
