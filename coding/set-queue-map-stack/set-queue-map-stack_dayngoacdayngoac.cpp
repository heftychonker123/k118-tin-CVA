#include <bits/stdc++.h>
using namespace std;
#define filename "daungoac"
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
    ll n ; cin >>n;
    str s ; cin >> s;
    ll t = 0;
    for (const char &i : s){
        if (i=='(') t++;
        else{
            if (t>0) t--;
            else{
                cout << "NO\n";return;
            }
        }
    }
    if (t>0) cout << "NO\n";
    else cout << "YES";
    return;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}