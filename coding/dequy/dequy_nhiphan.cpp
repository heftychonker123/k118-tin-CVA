#include <bits/stdc++.h>
using namespace std;
#define filename "nhiphan"
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
void solve(ll n , str sub = ""){
    if (sub.size() == n) {
        cout << sub << "\n";
        return;
    }
    solve(n , sub+"0");
    solve(n,sub+"1");
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    solve(n);
    return 0;
}