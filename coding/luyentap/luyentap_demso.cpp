#include <bits/stdc++.h>
using namespace std;
#define filename "DEMXAU"
#define ll long long
#define str string

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    str s ; getline(cin , s);
    ll x ; cin >> x;
    ll cnt = 0;
    for (int i=0 ; i<s.size()-1 ; i++){
        if (s[i] == 'a' && s[i+1] == 'b'){
            cnt++;
        }
    }
    ll wrap = 0;
    if (s[s.size()-1] == 'a' && s[0] == 'b') wrap = 1;
    cout << cnt*x + wrap*(x-1) << "\n";

    return 0;
}