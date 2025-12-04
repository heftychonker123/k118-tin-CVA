#include <bits/stdc++.h>
using namespace std;
#define filename "chuyenso"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,k ; cin >> n >> k;
    queue<ll> v;
    k%=n;
    while (n--){
        ll t ; cin >> t; v.push(t);
    }
    while (k--){
        ll temp = v.front(); v.pop();   
        v.push(temp);
    }
    while (!v.empty()){
        cout << v.front() << " ";
        v.pop();
    }
}