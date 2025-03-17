#include<iostream>
using namespace std;

int main(){
    int n, ans = 0, i = 1;
    cout <<"Enter the binary number: ";
    cin >> n;
    while(n > 0){
        ans += (n % 10) * i;
        n = n / 10;
        i *= 2;
    }
    cout << "Decimal equivalent: " << ans << endl;
}