#include <bits/stdc++.h>
using namespace std;
#define filename "chusonhonhat"
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
bool traverse(vect<ll> v , ll index){
    if (index == v.size()) return true;
    else{
        if (v[index]%2==0) return false;
        return traverse(v,index+1);
    }
}
void solve(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];

    if (traverse(v,0)) cout << "YES";
    else cout << "NO";
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