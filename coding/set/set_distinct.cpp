#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define str string

void solve(str s){
    int n = s.size();
    for (int i = 1 ; i<=n ; i++){
        set<str> t;
        for (int j = 0 ; j<n-i+1 ; j++){
            t.insert(s.substr(j , i));
        }
        if (t.size() == n-i+1){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ll n ; cin >> n;
    str s ; cin >> s;
    solve(s);
}