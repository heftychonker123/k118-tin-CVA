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
void solve(vect<ll> a , vect<ll> b , ll length){
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    for (int i=0 ; i<length ; i++){
        if (a[i]!=b[i]){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    return;
}

int main(){
    freopen("CHKSHOP.INP" , "r" , stdin);
    freopen("CHKSHOP.OUT" , "w" , stdout);
    int n; cin >> n;
    vect<ll> a(n) , b(n);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<n ; i++) cin >> b[i];
    solve(a,b,n);
}