#include <iostream>
#include <vector>

using namespace std;

// Function returns index of target if found, else -1
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Use this formula to avoid potential integer overflow
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // Target was not found
    return -1;
}

int main() {
    int data[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}; // Must be sorted
    int n = sizeof(data) / sizeof(data[0]);
    int target = 23;

    int result = binarySearch(data, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
