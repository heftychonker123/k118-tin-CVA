#include <bits/stdc++.h>
using namespace std;
#define filename "tansuat1"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    map<ll,ll> freq;
    ll n; cin >> n;
    while(n--){
        ll t;cin>>t;freq[t]++;
    }
    for (const auto &i : freq){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}