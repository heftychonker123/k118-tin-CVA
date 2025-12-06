#include <bits/stdc++.h>
using namespace std;
#define filename "intersect"
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

void solve(const vector<ll>& a, const vector<ll>& b) {
    unordered_set<ll> s(b.begin(), b.end());  // store elements of b
    unordered_set<ll> res;  // use set to keep results sorted
    for (const ll &i : a) {
        if (s.find(i) != s.end()) {
            res.insert(i);
        }
    }
    vect<ll> p;
    for (const ll &i : res){
        p.pb(i);
    }
    for (auto i = p.rbegin() ; i!=p.rend() ; i++){
        cout << *i << " ";
    }
    cout << "\n"; return;
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