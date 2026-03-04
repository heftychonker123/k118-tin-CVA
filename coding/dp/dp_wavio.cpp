#include <bits/stdc++.h>
using namespace std;
#define filename "wavio"
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

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<ll> v(n) ; for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> pis(n+1) , sis(n+1);
    for (int i=1 ; i<=n ; i++){
        pis[i] = 1;
        for (int j=1 ; j<i ; j++){
            if (v[i-1] > v[j-1]) pis[i] = max(pis[i] , pis[j] + 1);
        }
    }
    for (int i=n ; i>0 ; i--){
        sis[i] = 1;
        for (int j=n ; j>i ; j--){
            if (v[i-1] > v[j-1]) sis[i] = max(sis[i] , sis[j] + 1);
        }
    }
    ll res = LLONG_MIN;
    for (int i=1 ; i<=n ; i++) res = max(res , min(pis[i] , sis[i])*2 - 1);
    cout << res << "\n";
    return 0;
}