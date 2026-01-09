#include <bits/stdc++.h>
using namespace std;
#define filename "chuyendoi"
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
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n, k; 
    cin >> n >> k;
    queue<ll> q;

    for (int i = 0; i < n; i++) {
        ll t; 
        cin >> t;
        q.push(t);
    }

    k %= n; // optimize rotation
    while (k--) {
        ll t = q.front(); 
        q.pop();
        q.push(t);
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}