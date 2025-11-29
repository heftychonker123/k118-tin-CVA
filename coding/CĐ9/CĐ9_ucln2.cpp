#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string a, ll x, ll y){
    ll g = gcd(x, y);
    for (int i = 0; i < g; i++){
        cout << a;
    }
    cout << "\n";
}

int main(){
    string a;
    ll x, y;
    cin >> a >> x >> y;
    solve(a, x, y);
    return 0;
}
