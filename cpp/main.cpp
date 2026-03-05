#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Greeter {
private:
    string name;

public:
    Greeter(string n) : name(n) {}

    void sayHello() {
        cout << "Hello, " << name << "!" << std::endl;
    }
};

int main() {
    string userInput;

    cout << "Enter your name: ";
    // Use cin to capture a single word
    cin >> userInput; 

    Greeter myObject(userInput);
    myObject.sayHello();
    
    return 0;
}
