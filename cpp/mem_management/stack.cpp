#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DynamicStack {
    private:
        int* arr;        // Dynamic array
        int capacity;    // Maximum capacity
        int top;         // Current top index
    
    public:
        // Constructor
        DynamicStack(int size = 5) {
            capacity = size;
            arr = new int[capacity];
            top = -1;
        }
        
        // Destructor to free memory
        ~DynamicStack() {
            delete[] arr;
        }
        
        // Push operation
        void push(int value) {
            if(top >= capacity - 1) {
                // Resize if needed (optional feature)
                resize();
            }
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " to stack" << endl;
        }
        
        // Resize array when full
        void resize() {
            capacity *= 2;
            int* newArr = new int[capacity];
            for(int i = 0; i <= top; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            cout << "Stack resized to capacity: " << capacity << endl;
        }
        
        // Pop operation
        int pop() {
            if(top == -1) {
                cout << "Stack Underflow! Stack is empty" << endl;
                return -1;
            }
            int poppedValue = arr[top];
            top--;
            cout << "Popped " << poppedValue << " from stack" << endl;
            return poppedValue;
        }
        
        // Peek operation
        int peek() {
            if(top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return arr[top];
        }
        
        // Display all elements
        void display() {
            cout << "Stack (bottom to top): ";
            if(top == -1) {
                cout << "Empty";
            } else {
                for(int i = 0; i <= top; i++) {
                    cout << arr[i];
                    if(i < top) cout << " -> ";
                }
            }
            cout << " | Size: " << (top + 1) << "/" << capacity << endl;
        }
        
        bool isEmpty() { return top == -1; }
        int size() { return top + 1; }
};

int main() {
    DynamicStack s(3);  // Start with small capacity to demonstrate resizing
    
    cout << "=== Dynamic Stack Demo ===" << endl;
    s.push(4);
    s.push(7);
    s.push(2);
    s.display();
    
    cout << "\n--- Pushing beyond initial capacity ---" << endl;
    s.push(9);  // This will trigger resize
    s.push(5);
    s.display();
    
    cout << "\n--- Stack operations ---" << endl;
    cout << "Top value: " << s.peek() << endl;
    s.pop();
    s.display();
    
    return 0;
}