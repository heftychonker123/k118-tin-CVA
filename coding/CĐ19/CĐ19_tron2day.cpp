#include <bits/stdc++.h>
using namespace std;
#define filename "tron2day"
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
void solve(){
    ll n,m ; cin >> n >> m;
    vect<ll> a(n); for (int i=0 ; i<n ; i++) cin >> a[i];
    vect<ll> b(m); for (int i=0 ; i<m ; i++) cin >> b[i];
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());


    ll ptrA = 0 , ptrB = 0;
    while (ptrA<n && ptrB<m){
        if (a[ptrA] <= b[ptrB]){
            cout << "A" << ptrA + 1 << " "; ptrA++;
        }
        else{
            cout << "B" << ptrB + 1 << " "; ptrB++;
        }
    }
    while (ptrA<n){
        cout << "A" << ptrA + 1 << " "; ptrA++;
    }
    while (ptrB<m){
        cout << "B" << ptrB + 1 << " "; ptrB++;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}