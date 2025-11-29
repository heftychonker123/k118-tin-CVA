#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n , ll t){
    ll prev1 = 1;
    ll prev2 = 1;

    if (n == 1) {
        cout << prev1 % t;
        return;
    }
    if (n == 2) {
        cout << prev2 % t;
        return;
    }

    n -= 2;
    while (n--) {
        ll curr = ( (5 * prev1) % t + prev2 ) % t;
        prev1 = prev2;
        prev2 = curr;
    }
    cout << prev2;
}

int main(){
    ll n, t;
    cin >> n >> t;
    solve(n, t);
    return 0;
}
