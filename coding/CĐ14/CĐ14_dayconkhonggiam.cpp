#include <bits/stdc++.h>
using namespace std;
#define filename "maxiseq"
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

bool check(ll x){
    ll t = 1+8*x;
    if (sqrtl(t)*sqrtl(t) == t){
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll res=0;
    ll temp=0;
    ll prev = llmin;
    for (const ll &i : v){
        if (check(i) && prev<=i){
            temp++;
            prev=i;
        }
        else{
            res=max(res,temp);
            temp=0;
            prev=llmin;
        }
    }
    res=max(res,temp);
    cout << res << "\n";
    return 0;

}