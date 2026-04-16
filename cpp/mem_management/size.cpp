#include <iostream>
#include <string>
using namespace std;


int main(){
    //4 bytes
    int a = 4;
    //4 bytes
    float b = 4.5;
    //8 bytes
    double c = 4.23423;
    // 32 bytes; ie 4 characters each 8
    string d = "sdssd";
    //no string is 32 bytes
    string e = "s";
    //the [7] buffers 7 bytes
    char _e[4] = "sdd";
    // __e = "dd";
    int size_a = sizeof(a);
    int size_b = sizeof(b);
    int size_c = sizeof(c);
    int size_d = sizeof(d);
    int size_e = sizeof(e);
    int size_char = sizeof(_e);

     cout << "sizes of a,b,a,d(int,float,double,string) " << size_a << " bytes " << size_b << " bytes " << size_c << " bytes " << size_d << " bytes" << std::endl;

     cout << "size of e is " << size_e << " bytes" << std::endl;

     cout << "size of char is " << size_char << " bytes" << std::endl;
};