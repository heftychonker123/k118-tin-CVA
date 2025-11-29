#include <bits/stdc++.h>
using namespace std;
#define filename "guess"
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
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    
    long long n, m; 
    cin >> n >> m;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    long long result = -1;
    
    for (long long i = 0; i < n-1; i++){
        if (abs(v[i] - v[i+1]) < m){
            result = i + 1;
        }
    }
    cout << result << "\n";
    return 0;
}