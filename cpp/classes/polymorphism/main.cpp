#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//polymorhism is taking different forms and different behaviour but same interface 
//ie shape.takes rectangle and triangle

//ie payment system
//payment class has pure virtual funstions
// card payment , mpesa , paypal (they have their specific logic)




//drawing app
//fill width

//1. users download diff
//entity
//shape parent
//triangle circle(children) ihnerit but overide

//abstract class
class Payment{
    protected:
    int amount;

    public:
    Payment(int _amount){
     amount = _amount;
    }; //initial state


    //or 
    virtual void makePayment() = 0; //pure virtual function

};

class CardPayment:public Payment{
    protected:
    int h;//specific to the triangle child class
    //methods
    public:
    //constructor method
   CardPayment(int x, int y):

   void makePayment() override{
    cout<< "making Card Payment"<< endl;
   };

};


/*
base class pointer..pointer whose type is the base class
[x,y,h] derived Base
point to base and derived
*/
int main(){

   
    //base pointer (makes manipulation of larger data easier)
    payment = new CardPayment(100)

    return 0;
}