#include <bits/stdc++.h>
using namespace std;
#define filename "chianhom"
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

void solve(){
}

int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n,k ; cin >> n >> k;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll left = 0;
    ll seq = 1;
    for (int i=0 ; i<n ; i++){
        if ((v[i] - v[left]) > k){
            seq++;
            left = i;
        }
    }
    cout << seq;
    return 0;
}