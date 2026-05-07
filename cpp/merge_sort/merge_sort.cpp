#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    //n1 i lenath of the fisrt sub array, n2 is length of 2nd sub array
    int n1 = m - l + 1, n2 = r - m;
    //create the left and right sub arrays
    vector<int> L(n1), R(n2);
    //push the values in the fisrt and 2nd sub arrays
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// main() function to call mergeSort(data, 0, data.size() - 1)


int main(){
    vector<int> data = {12, 11, 13, 5, 6, 7};
    mergeSort(data, 0, data.size() - 1);
    for (int i = 0; i < data.size(); i++) cout << data[i] << " ";
    return 0;

}