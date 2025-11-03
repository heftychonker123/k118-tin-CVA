#include <bits/stdc++.h>
using namespace std;
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
    umap<char , ll> freq;
    ll ans=0;
    for (const char &i : n){
        freq[i]++;
    }
    for (auto &i : freq){
        ll t=i.second;
        ans += t*(t+1)/2;
    }
    cout << ans;
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    str n ; getline(cin , n) ; solve(n);
    return 0;
}