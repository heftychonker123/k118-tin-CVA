#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a = sqrt(n);
    if (a*a==n){
        cout << "CHINH PHUONG";
    }
    else{
        cout << "KHONG CHINH PHUONG";
    }
    return 0;
}