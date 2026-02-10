#include <bits/stdc++.h>
using namespace std;
#define filename "demsothaotac"
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
ll calc(ll n , ll step){
    if (n==1) return step;
    else{
        if (n%2==0) return calc(n/2 , step+1);
        if (n%3==0) return calc(n/3 , step+1);
        return calc(n-1 , step+1);
    }
}
void solve(){
    ll n ; cin >> n;
    cout << calc(n , 0);
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