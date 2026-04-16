#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    //we can push any type structures etc
    vector<int> v = {1,3,5,7};
    //has size 4
    cout << v.size();
    int size = v.size();
    //push_back , pop_back
    for (int i = 0; i <= size; i++){
      cout << v[i];
    };

    v.push_back(80);

    for (int i = 0; i <= size; i++){
      cout << v[i];
    };

    v.pop_back();


    for (int i = 0; i <= size; i++){
      cout << v[i];
    };

    return 0;
};