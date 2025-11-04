#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    bool ans=false;
    if (n%400==0) ans=true;
    else if (n%4==0 && n%100!=0) ans=true;
    if (ans) cout << "YES";
    else cout << "NO";
    return 0;
}