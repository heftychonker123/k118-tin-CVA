#include <bits/stdc++.h>
using namespace std;
#define filename "prefixsum2d"
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

vect<vect<ll>> prefix_sum_2d(vect<vect<ll>> v , ll height , ll width){
    vect<vect<ll>> res(height , vect<ll>(width,0));
    for (int i=0 ; i<height ; i++){
        for (int j=0 ; j<width ; j++){
            res[i][j]+=v[i][j];
            if (i>0){
                res[i][j] += res[i-1][j];
            }
            if (j>0){
                res[i][j] += res[i][j-1]; 
            }
            if (i>0 && j>0){
                res[i][j] -= res[i-1][j-1];
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,m ; cin >> n >> m;
    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin >> v[i][j];
        }
    }
    vect<vect<ll>> ans = prefix_sum_2d(v , n , m);
}