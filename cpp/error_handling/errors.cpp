#include <iostream>
#include <stdexcept> // Includes standard exception classes

int main() {
    try {
        int numerator = 10;
        int denominator = 0;

        if (denominator == 0) {
            // Throwing a standard runtime_error exception
            throw std::runtime_error("Division by zero error!");
        }

        std::cout << "Result: " << (numerator / denominator) << std::endl;
    } 
    catch (const std::runtime_error& e) {
        // Catching the specific error and accessing its message via what()
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    catch (...) {
        // Catch-all block for any other type of exception
        std::cerr << "Caught an unknown exception." << std::endl;
    }

    return 0;
}