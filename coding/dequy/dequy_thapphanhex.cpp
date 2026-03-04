#include <bits/stdc++.h>
using namespace std;
#define filename "tptlp"
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


vector<string> hexDigits = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

str convert(ll n , str res){
    if (n==0){
        if (!res.empty()) return res;
        else return "0";
    }
    res = hexDigits[n%16] + res;
    return convert(n/16 , res);
}
void solve(){
    ll n ; cin >> n;
    cout << convert(n , "");
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