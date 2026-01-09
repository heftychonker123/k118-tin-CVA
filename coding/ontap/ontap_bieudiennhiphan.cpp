#include <bits/stdc++.h>
using namespace std;
#define filename "Bai4"
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
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    str n ; cin >> n;
    ll z = 1;
    ll res=0;
    for (int i=n.size()-1 ; i>-1 ; i--){
        ll t = n[i]-'0';
        res+=z*t;
        z*=2;
    }
    cout << res;
}