#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Stack {
    private:
    int *arr[5];
    //track the top most value of stack
    int top = -1;
    //as we push we icrement the value top
    public:
    void push(int *a){
        top ++;
        arr[top + 1] = a;
    };

    int pop(){
        //if the value is -1 it means the stack is empty
        //return the top most value
        if(top == -1){
          return;
        }else{
           //if the stack has values we will remove 
           delete(arr[0]);
           top--;
        }
    };

    void peep(){
        //return the top most value in the stack
        cout << "value" << arr[0];
    }

    //we can hhave void display
    void display(){
        //loop through the elements in the stack and display
        for (int i= 0; i < 5; i++){
           cout << arr[i];
        };
    };

};



int main(){
    //class array
    //provide a push and pop method
    Stack s;
    int value = 4;
    s.push(&value);

    s.display();

    s.pop();

    s.display();

    s.peep();

    s.display();

    return 0;

}