#include <bits/stdc++.h>
using namespace std;
#define filename "thomecung"
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
ll t = 0;
void solve(ll n, vect<vect<ll>> v , str path = "" , ll x=0 , ll y=0){
    if (x>=n || y>=n) return;
    if (v[x][y] == 0) return;
    if (x==n-1 && y==n-1){
        cout << path << "\n";
        t++;
        return;
    }
    solve(n , v , path+"D" , x+1 , y);
    solve(n , v , path+"R" , x , y+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<vect<ll>> v(n , vect<ll>(n)); for (int i=0 ; i<n ; i++){for (int j=0 ; j<n ; j++) cin >> v[i][j];}
    solve(n,v);
    if (t==0) cout << -1;
    return 0;
}