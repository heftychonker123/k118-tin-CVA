#include <bits/stdc++.h>
using namespace std;
#define filename "dichuyen"
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
ll solve(ll n , ll m , vect<vect<ll>> &memo , ll x = 1, ll y = 1){ 
    // x là độ cao , y là độ dài
    if (y>m || x>n) return 0;
    if (x==n && y==m) return 1;
    if (memo[x-1][y-1] != -1) return memo[x-1][y-1];
    ll down = solve(n , m , memo , x+1 , y);
    ll right = solve(n , m , memo , x , y+1);
    return memo[x-1][y-1] = down + right;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m ; cin >> n >> m;
    vect<vect<ll>> memo(n , vect<ll>(m , -1));
    cout << solve(n , m , memo);
    return 0;
}