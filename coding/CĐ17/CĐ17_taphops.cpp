#include <bits/stdc++.h>
using namespace std;
#define filename "taphops"
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
ll solve(ll n , ll k , ll s , ll idx=0){
    if (k==0){
        if (s==0) return 1;
        else return 0;
    }
    else if (idx > n) return 0;
    ll res = 0;
    for (int i=idx+1 ; i<=n ; i++){
        if ((s-i)>=0){
            res += solve(n , k-1 , s-i , i);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,s ; cin >> n >> k >> s;
    cout << solve(n , k , s);
    return 0;
}