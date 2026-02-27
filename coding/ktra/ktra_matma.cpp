#include <bits/stdc++.h>
using namespace std;
#define filename "matma"
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
bool validLength(long long length, long long n, string s) {
    for (int i = 0; i < n; i++) {
        map<char, long long> freq;
        for (int j = 0; j < length; j++) {
            char c = s[(i + j) % n];
            if (c == '0') continue;
            freq[c]++;
        }
        if (freq.size() <= 1) return true;
    }
    return false;
}
void solve(){
    str s ; cin >> s;
    ll n = s.size();
    ll l = 1 , r = s.size();
    ll res = 0;
    while (l<=r){
        ll m = (l+r)/2;
        if (validLength(m , n , s)){
            res = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout << res;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}