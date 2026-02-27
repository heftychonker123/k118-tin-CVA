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

void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    str c; cin >> c;
    ll left=0 , right=0;
    ll res=0;
    while (right < n){
        str temp = c.substr(left , right-left+1);
        set<ll> s(temp.begin() , temp.end());
        if (s.size() == temp.size()){
            res = max(res , (ll)temp.size());
            right++;
        }
        else{
            left++;
        }
    }
    cout << res << "\n";
    return 0;
}