#include <bits/stdc++.h>
using namespace std;
#define filename "prefix_sum"
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

vect<ll> prefix_sum(vect<ll> v){
    vect<ll> res;
    ll sum=0;
    for (const ll &i : v){
        sum+=i ; res.pb(sum);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    for (const ll &i : prefix_sum(v)){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}