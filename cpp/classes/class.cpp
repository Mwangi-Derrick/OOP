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

int addr;
// void fetchpass(Passenger P){
// P.getId();
// };

int fetchpass(Passenger& P){
   int addr = P.getId();
   return addr;
};

// void fetchpass(Passenger* P){
//     P->setID(20);
// };


Passenger createPassenger(){
    Passenger P(1 , "John", "gmail.com");
    return P;
};

int main(){
Passenger pass1 = createPassenger();
int value = fetchpass(pass1);
cout << "value:" << value;
return 0;
};