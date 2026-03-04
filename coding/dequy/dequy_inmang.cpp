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
void traverse(vect<ll> v , ll index){
    if (index == v.size()) return;
    else{
        cout << v[index] << " ";
        traverse(v,index+1);
    }
}
void rtraverse(vect<ll> v , ll index){
    if (index == -1) return;
    else{
        cout << v[index] << " ";
        rtraverse(v,index-1);
    }
}
void solve(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    traverse(v,0);
    cout << "\n";
    rtraverse(v,n-1);
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