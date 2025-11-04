#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string




void solve(str n) {
    ll left_bracket = 0;
    for (const char &i : n) {
        if (i == '(') {
            left_bracket++;
        } 
        else if (i == ')') {
            if (left_bracket > 0) {
                left_bracket--;
            } 
            else {
                cout << "KHONGDUNG\n";
                return;
            }
        } 
        else {
            cout << "KHONGHOPLE\n";
            return;
        }
    }
    if (left_bracket == 0) {
        cout << "DUNG\n";
    } else {
        cout << "KHONGDUNG\n";
    }
}




int main(){
    freopen("KTNGOAC.INP" , "r" , stdin);
    freopen("KTNGOAC.OUT" , "w" , stdout);
    str s;
    while (getline(cin, s)) {
        if (s.empty()) continue;
        solve(s);
    }
    return 0;
}  