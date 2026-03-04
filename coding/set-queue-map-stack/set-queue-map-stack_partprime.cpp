#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

bool check(ll n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2){
        if (n % i == 0) return false;
    }
    return true;
}

ll helper_function(str n, ll substring_length){
    ll length = n.size();
    ll res = 0;
    vector<ll> shit;
    for (int i = 0; i <= length - substring_length; i++){
        str temp = "";
        for (int t = 0; t < substring_length; t++){
            temp += n[i+t];
        }
        ll temp2 = stoll(temp);
        shit.push_back(temp2);
    }
    set<ll> s(shit.begin() , shit.end());
    for (const ll &i : s){
        if (check(i)) res++;
    }
    return res;
}

void solve(str n){
    ll res = 0;
    for (int i = 1; i <= n.size(); i++){
        res += helper_function(n, i);
    }
    if (res == 0) cout << "NO PRIMES";
    else cout << res;
    cout << "\n";
}

int main(){
    //freopen("prime.inp", "r", stdin);
    //freopen("prime.out", "w", stdout);
    str n; 
    cin >> n;
    solve(n);
}
