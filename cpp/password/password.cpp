#include <iostream>
#include <string>
#include <math.h>

using namespace std;
string password;
int chances;
int attempt;
string username;
string correctpwd;
string correct_username;

void prompt(){
    cout << "Enter your Username \n";
    cin >> username;
    cout << "Enter your password \n";
    cin >> password;
}

void compare(){
if (password != correctpwd || username != correct_username){
   if (attempt == chances ){
    cout << "Your account is locked";
   }
   else {
     cout << "You have used " << attempt << " out of" << " 3 chances. Try again \n";
     attempt += 1;
     prompt();
     compare();
   }

}
else if (password == correctpwd && username == correct_username) {
cout << "Access granted";
return;
}
}


int main(){
    attempt = 1;
    chances = 3;
    correct_username = "ADMIN";
    correctpwd = "1234";
    prompt();
    compare();
    return 0;
}