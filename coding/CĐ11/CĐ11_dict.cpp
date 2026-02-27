#include <bits/stdc++.h>
using namespace std;
#define filename "dict"
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll q ; cin >> q;
    umap<str,ll> freq;
    while (q--){
        ll t; str b;
        cin >> t >> b;
        if (t==1){
            freq[b]++;
        }
        else{
            cout << freq[b]<<"\n";
        }
    }
    return 0;
}