#include <bits/stdc++.h>
using namespace std;
#define filename "lonhon__"
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(x);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < x; i++) cin >> b[i];

    sort(b.begin(), b.end()); // sort b for binary search
    for (const ll &i : a){
        auto it = lower_bound(b.begin() , b.end() , i);
        cout << b.end() - it << " ";
    }
    cout << "\n";
    return 0;
}