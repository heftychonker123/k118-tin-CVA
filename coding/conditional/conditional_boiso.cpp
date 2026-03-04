#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,y; cin >> x >> y;
    if (x==0) cout << "INVALID";
    else if (y%x == 0) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}