#include <bits/stdc++.h>
using namespace std;
#define filename "selsort"
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

void solve(vect<ll> arr, ll n) {
    for (ll i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]);

        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cout << arr[j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solve(v, n);
    return 0;
}
