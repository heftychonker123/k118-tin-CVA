#include <bits/stdc++.h>
using namespace std;
#define filename "union"
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

void solve(vect<ll> a , vect<ll> b){
    set<ll> s;
    for (const ll &i : a) s.insert(i);
    for (const ll &i : b) s.insert(i);
    for (auto i = s.rbegin() ; i!=s.rend() ; i++){
        cout << *i << " ";
    }
    cout << "\n";
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int n,m ; cin >> n >> m;
    vect<ll> a(n);
    vect<ll> b(m);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<m ; i++) cin >> b[i];
    solve(a,b);
    return 0;
}