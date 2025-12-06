#include <bits/stdc++.h>
using namespace std;
#define filename "phantuphanbiet"
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

void solve(vect<str> v){
    set<str> s;
    for (const auto &i:v){
        s.insert(i);
    }
    cout << s.size() << "\n";
    for (const auto &i:s) cout << i << " ";
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int n; cin >> n;
    vect<str> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    solve(v);
    return 0;
}