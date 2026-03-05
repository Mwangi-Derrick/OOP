#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int radius;

float PI = 3.142;

float getArea (int radius){
float area = PI * pow(radius, 2);
return area;
}

int main(){
    cout << "Enter the radius: ";
    cin >> radius;
     
    float area = getArea(radius);

    cout << "The area of the circle is: " << area;

}


