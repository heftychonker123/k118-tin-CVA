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

void solve(str n , ll m){
    while(n.size()<4) n = "0"+n;
    str t = n.substr(n.size()-4,4);
    ll temp = stoi(t);
    ll res=1;
    for (int i=0 ; i<m ; i++){
        res *= temp%1000;
        res %= 1000;
    }
    cout << res;
    return;
}

int main(){
    str n; ll m ; cin >> n >> m;
    solve(n,m);
    return 0;
}