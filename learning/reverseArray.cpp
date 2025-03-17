#include<iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int start = 0;
    int end = size - 1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    cout << "Reversed array is: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {5, 15, 22, 1, -15, -24, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, n);
}