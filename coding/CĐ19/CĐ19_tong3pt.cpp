#include <bits/stdc++.h>
using namespace std;
#define filename "tong3pt"
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
    ll n,s ; cin >> n >> s;
    ll a[n] ; for (int i=0 ; i<n ; i++) cin >> a[i];
    for (ll i=0 ; i<n ; i++){
        ll start = i+1 , end = n-1;
        while (start<end){
            if (a[i] + a[start] + a[end] == s){
                cout << "YES";
                return;
            }
            else if (a[i] + a[start] + a[end] < s) start++;
            else end--;
        }
    }
    cout << "NO";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}