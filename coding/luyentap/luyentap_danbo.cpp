#include <bits/stdc++.h>
using namespace std;
#define filename "danbo"
#define ll long long
#define vect vector
#define FOR(i , m , n) for (ll i=m ; i<n ; i++)

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r")){
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

void allVal(ll n , ll i , vect<ll> &v , vect<ll> &allSum , ll currSum){
    if (i==n){
        allSum.push_back(currSum);
        return;
    }
    allVal(n , i+1 , v , allSum , currSum + v[i]);
    allVal(n , i+1 , v , allSum , currSum);
}

int main(){
    IO();
    ll n; cin >> n;
    vect<ll> v(n); FOR(i , 0 , n) cin >> v[i];

    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll res = LLONG_MAX;

    vect<ll> left, right;
    allVal(n/2 , 0 , v , left , 0);
    allVal(n , n/2 , v , right , 0);
    sort(left.begin() , left.end());
    sort(right.begin() , right.end());
    for (ll i : left){
        ll target = sum - 2*i;
        auto larger = lower_bound(right.begin() , right.end() , target/2);
        auto smaller = larger;
        if (larger != right.end()){
            ll lSum = *larger + i;
            res = min(res, abs(sum - 2*lSum));
        }
        if (smaller != right.begin()){
            smaller--;
            ll sSum = *smaller + i;
            res = min(res, abs(sum - 2*sSum));
        }
    }
    cout << res;
    return 0;
}
