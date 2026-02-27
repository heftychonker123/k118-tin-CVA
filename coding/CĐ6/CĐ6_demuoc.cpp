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

void solve(ll n){
    ll res=0;
    for (int i=1 ; i*i <= n ; i++){
        if (n%i == 0){
            if (i*i==n) res+=1;
            else res+=2;
        }
    }
    cout << res;
    return;
}

int main(){
    int n; cin >> n;
    solve(n);
    return 0;
}