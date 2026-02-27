#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin >> a >> b;
    if (a<=0 || b<=0){
        cout << "KHONG LA HINH GI";
    }
    else if (a==b){
        cout << "HINH VUONG";
    }
    else{
        cout << "HINH CHU NHAT";
    }
    return 0;
}