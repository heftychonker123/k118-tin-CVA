#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
template <typename T>
using vect = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<ll> v; v.pb(n);
    vect<vect<ll>> res;
    while (true) {
        res.pb(v);
        ll old_size = v.size();
        ll i = v.size() - 1;
        while (i > -1 && v[i] == 1) {
            i--;
            v.pop_back();
        }
        if (i == -1) break;

        v[i]--;
        ll rem = (old_size - i - 1) + 1;

        while (rem > v[i]) {
            v.pb(v[i]);
            rem -= v[i];
        }
        v.pb(rem);
    }
    cout << res.size() << "\n";
    for (const auto &i : res){
        for (int j=0 ; j<i.size()-1 ; j++){
            cout << i[j] << "+";
        }
        cout << i[i.size()-1] << "\n";
    }
}
