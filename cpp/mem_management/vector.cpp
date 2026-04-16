#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // fixed typo: <algorithm> has reverse, unique, sort, min/max functionality
using namespace std;

int main(){
    // Initialize vector with values
    vector<int> v = {1,3,5,7};
    
    // Display size
    cout << "Initial size: " << v.size() << endl;
    cout << "Initial elements: ";
    for (int i = 0; i < v.size(); i++){  // Fixed: use < not <= to avoid out of bounds
        cout << v[i] << " ";
    }
    cout << endl << endl;
    
    // Push back a new element
    v.push_back(80);
    cout << "After push_back(80): ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << " (Size: " << v.size() << ")" << endl << endl;
    
    // Pop back the last element
    v.pop_back();
    cout << "After pop_back(): ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << " (Size: " << v.size() << ")" << endl << endl;
    
    // Additional useful vector operations
    cout << "=== Additional Operations ===" << endl;
    
    // Insert at position
    v.insert(v.begin() + 2, 10);  // Insert 10 at index 2
    cout << "After insert at index 2: ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    // Erase an element
    v.erase(v.begin() + 1);  // Erase element at index 1
    cout << "After erase at index 1: ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    // Using algorithms from <algorithm>
    vector<int> v2 = {5, 2, 8, 1, 9, 3};
    cout << "\nNew vector v2: ";
    for (int num : v2) cout << num << " ";
    cout << endl;
    
    // Sort
    sort(v2.begin(), v2.end());
    cout << "After sorting: ";
    for (int num : v2) cout << num << " ";
    cout << endl;
    
    // Reverse
    reverse(v2.begin(), v2.end());
    cout << "After reversing: ";
    for (int num : v2) cout << num << " ";
    cout << endl;
    
    // Find min and max
    cout << "Minimum element: " << *min_element(v2.begin(), v2.end()) << endl;
    cout << "Maximum element: " << *max_element(v2.begin(), v2.end()) << endl;
    
    // Range-based for loop (C++11 and later)
    cout << "\nUsing range-based for loop: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}