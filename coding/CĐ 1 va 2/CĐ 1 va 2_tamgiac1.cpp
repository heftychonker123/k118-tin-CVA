#include <bits/stdc++.h>
using namespace std;

int main(){
    long a,b,c; cin >> a >> b >> c;
    if (a==0 || b==0 || c==0 || a>=b+c || b>=c+a || c>=a+b) cout << "FALSE";
    else cout << "TRUE";
}