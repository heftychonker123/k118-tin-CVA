#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define umap unordered_map

vect<ll> sieve(ll limit){
    vect<bool> prime(limit+1 , true);
    vect<ll> res;
    prime[0] = prime[1] = false;
    for (ll i=2 ; i<=limit ; i++){
        if (prime[i]){
            res.push_back(i);
            for (ll j=i*i ; j<=limit ; j+=i){
                prime[j]=false;
            }
        }
    }
    return res;
}

void solve(ll n){
    map<ll , ll> pfact;
    vect<ll> prime = sieve(sqrt(n));
    ll temp=0;
    while(n!=1 && temp<prime.size()){
        if (n % prime[temp] == 0){
            n/=prime[temp];
            pfact[prime[temp]] ++;
        }
        else temp++;
    }
    if (n>1){
        pfact[n]++;
    }
    ll res=1;
    vect<ll> z;
    for (auto &p : pfact){
        for (int i=0 ; i< p.second ; i++){
            z.push_back(p.first);
        }
        res *= (p.second+1);
    }
    cout << res << " ";
    for (int i=0 ; i<z.size()-1 ; i++){
        cout << z[i] << "*";
    }
    cout << z[z.size()-1] << "\n";
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        solve(n);
    }
    return 0;
}
