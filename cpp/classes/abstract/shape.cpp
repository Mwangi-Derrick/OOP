#include <iostream>
#include <string>
using namespace std;

//drawing app
//fill width

//1. users download diff
//entity
//shape parent
//triangle circle(children) ihnerit but overide

//abstract class
class Shape{
    protected:
    int x,y;

    public:
    Shape(int _x,int _y){
     x = _x ;
     y = _y;
    }; //initial state
    void printInto(){
        cout << "coordinates " << x << " ," << y << endl;
    };

    // virtual void draw(){
    //     cout<<"Draw generic shape";
    // };

    //or 
    virtual void draw() = 0; //pure virtual function

};

class Triangle:public Shape{
    protected:
    int h;//specific to the triangle child class
    //methods
    public:
    //constructor method
   Triangle(int x, int y, int _h):
   Shape(x,y){
    h = _h;
   }
   void draw() override{
    cout<< "Draw Triangle"<< endl;
   };

};


class Rectangle:public Shape{
    protected:
    int l;
    int w;//specific to the triangle child class
    //methods
    public:
    //constructor method
   Rectangle(int x, int y, int _w, int _l ):
   Shape(x,y){
    w = _w;
    l = _l;
   }
   void draw() override{
    cout<< "Draw Rectangle"<< endl;
   };

};


/*
base class pointer..pointer whose type is the base class
[x,y,h] derived Base
point to base and derived
*/
int main(){
    //direct objects
    // Triangle triangle1(20, 20, 10);
    // triangle1.draw();

    // Triangle t(10, 10 , 12);
    // t.draw();
    
   
    //base pointer (makes manipulation of larger data easier)
    Shape *s1 = new Triangle(3, 4, 5); //create and get address
    s1->draw();
    s1->printInto();
    Shape *s2 = new Rectangle(9, 10, 3, 5);
    s2->draw();
    s2->printInto();
    //remove the memory
    delete s1;
    delete s2; 
    
    // Triangle *p = &t;
    // Shape *p = new;
    // cout << "pointer " << p;
    //base class pointer..pointer whose type is the base class
    // int x = 45;
    // int *p = &x;
    // cout << "variable:" << x << "  address: " << p << endl;
    return 0;
}