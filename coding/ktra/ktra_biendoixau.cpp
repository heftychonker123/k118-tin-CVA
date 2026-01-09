#include <bits/stdc++.h>
using namespace std;
#define filename "biendoixau"
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str n ; cin >> n;
    ll l=n.size();
    ll res = l*(l-1)/2 + 1;
    map<ll,ll> freq;
    for (const char &i : n){
        res -= freq[i];
        freq[i]++;
    }
    cout << res << "\n";
    return 0;
}