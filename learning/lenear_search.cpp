#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5, 15, 22, 1, -15, -24, 0, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 22;
    int result = linearSearch(arr, n, x);
    if(result == -1){
        cout << "Element is not present in the array" << endl;
    }else{
        cout << "Element is present at index: " << result << endl;
    }
}