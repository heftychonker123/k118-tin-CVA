#include <bits/stdc++.h>
using namespace std;
#define filename "xauconphanbiet"
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

void solve(str n){
    set<char> sub;
    vect<ll> length;
    for (const char &i : n){
        if (sub.find(i) == sub.end()){
            sub.insert(i);
        }
        else{
            length.pb(sub.size());
            while(sub.find(i) != sub.end()) sub.erase(sub.begin());
        }
    }
    length.pb(sub.size());
    cout << *max_element(length.begin() , length.end());
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll t; cin >> t;
    str n ; cin >> n;
    solve(n);
    return 0;
}