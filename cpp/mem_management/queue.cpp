#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DynamicQueue {
private:
    vector<int> queue;  // Dynamic array that grows as needed
    
public:
    // Add to the back (rear)
    void enqueue(int value) {
        queue.push_back(value);
        cout << "Enqueued " << value << " to queue" << endl;
    }
    
    // Remove from the front
    int dequeue() {
        if(queue.empty()) {
            cout << "Queue Underflow! Queue is empty" << endl;
            return -1;
        }
        int frontValue = queue.front();
        queue.erase(queue.begin());  // Remove first element
        cout << "Dequeued " << frontValue << " from queue" << endl;
        return frontValue;
    }
    
    // Peek at front
    int peek() {
        if(queue.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue.front();
    }
    
    // Check if empty
    bool isEmpty() {
        return queue.empty();
    }
    
    // Get size
    int getSize() {
        return queue.size();
    }
    
    // Display
    void display() {
        cout << "Queue (front -> rear): ";
        if(queue.empty()) {
            cout << "Empty";
        } else {
            for(int i = 0; i < queue.size(); i++) {
                cout << queue[i];
                if(i < queue.size() - 1) cout << " -> ";
            }
        }
        cout << " | Size: " << queue.size() << endl;
    }
};

int main() {
    DynamicQueue q;
    
    cout << "=== Dynamic Queue Demo (No Size Limit) ===" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    
    cout << "\nServing customers (FIFO order):" << endl;
    q.dequeue();  // Serves 10
    q.display();
    q.dequeue();  // Serves 20
    q.display();
    q.dequeue();  // Serves 30
    q.display();
    
    return 0;
}


// Visual representation of queue operations:
/*
Initial empty queue:
[ ] [ ] [ ] [ ] [ ]
 f,r (both point to same)

After enqueue(10):
[10] [ ] [ ] [ ] [ ]
 f   r

After enqueue(20):
[10] [20] [ ] [ ] [ ]
 f        r

After enqueue(30):
[10] [20] [30] [ ] [ ]
 f             r

After dequeue() - removes 10:
[ ] [20] [30] [ ] [ ]
     f    r

After enqueue(40):
[ ] [20] [30] [40] [ ]
     f         r

This is a CIRCULAR QUEUE - when rear reaches end, it wraps around!
*/