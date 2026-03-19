#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Passenger {
    //atributes
    private:
    int id;
    string name;
    string email;

   public:
    //methods
    Passenger(int i , string n, string e){
        id = i;
        name = n;
        email = e;
    }
   //setter
   void setID(int i){
   id = i;
   };
   void setEmail(string e){
    email = e;
   };
   void setName(string n){
    name = n;
   };

   //getter
   int getId(){return id;};
   string getName(){return name;};
   string getEmail(){return email;};

void displayDetails(){
    cout <<id << name << email;
};

};