#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// compile time polymorhism -> method overloading(same scope )
// runtime polymorphism -> funstion overiding(parent class and child classes)

//function overloading 

class Calculator{
    public:
    int add(int x, int y){
        return x + y;
    };
    float add(float x , float y){
        return x + y;
    };
   int add(int x, int y, int z){
    return x + y + z;
   };
};

int main(){
    Calculator c1;
    //static binding and dynamic binding
    c1.add(3,4);
    c1.add(3.5,5.8);
    c1.add(3,4,5);
    return 0;
}