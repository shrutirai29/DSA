#include<iostream>
using namespace std;

int main(){
    int n, ans = 0, i = 1;
    cout <<"Enter the decimal number: ";
    cin >> n;
    while(n > 0){
        ans += (n % 2) * i;
        n = n / 2;
        i *= 10;
    }
    cout << "Binary equivalent: " << ans << endl;
}