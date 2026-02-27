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

int main(){
    freopen("maxmin.inp" , "r" , stdin);
    freopen("maxmin.out" , "w" , stdout);
    int m,n ; cin >> m >> n;
    vect<ll> max_col(n,llmin);
    for (int rows=0 ; rows<m ; rows++){
        for (int cols=0 ; cols<n ; cols++){
            ll t; cin >> t;
            max_col[cols]=max(max_col[cols],t);
        }
    }
    cout << min_element(max_col.begin() , max_col.end())-max_col.begin()+1<< "\n";
    return 0;
}