#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n){
    ll limit = sqrtl(n);
    vector<bool> prime(limit+1, true);
    prime[0] = prime[1] = false;
    ll res=0;
    for (ll i = 2; i*i <= limit; i++){
        if (prime[i]){
            for (ll j = i*i; j <= limit; j += i){
                prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= limit; i++){
        if (prime[i]) res++;
    }
    cout << res << "\n";
    return;
}

int main(){
    ll n; cin >> n;
    solve(n);
    return 0;
}
