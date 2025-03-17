#include<iostream>
using namespace std;

int main(){
    int arr[] = {5, 15, 22, 1, -15, -24, 0, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int smallest = INT16_MAX;
    int i, imp;
    for(i = 0; i < n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
            imp = i;
        }
    }
    cout << "Smallest number is present at index: "<< imp << " and the number is = " << smallest << endl;
}