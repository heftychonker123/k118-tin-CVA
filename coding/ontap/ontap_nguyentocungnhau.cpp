#include <bits/stdc++.h>
using namespace std;
#define filename "nguyentocungnhau"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

bool check(ll n){
    if (n<2) return false;
    if (n==2) return true;
    for (int i=2 ; i*i<=n ; i++){
        if (n%i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll res=0;
    for (int i=0 ; i<n ; i++){
        for (int j=i+1 ; j<n ; j++){
            if (v[i]>1 && v[j]>1 && gcd(v[i] , v[j])==1) res++;
        }
    }
    cout << res;
}