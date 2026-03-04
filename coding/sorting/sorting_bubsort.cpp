#include <bits/stdc++.h>
using namespace std;
#define filename "bubsort"
#define ll long long
#define vect vector

void solve(vect<ll> v , ll length){
    for (int i = 0; i < length - 1; i++) {
        for (int t = 0; t < length - i - 1; t++) {
            if (v[t] > v[t + 1]) {
                swap(v[t], v[t + 1]);
            }
        }
        cout << "Vong lap " << i + 1 << ": ";
        for (int j = 0; j < length; j++) {
            cout << v[j];
            if (j < length - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solve(v, n);
    return 0;
}
