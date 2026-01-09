#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define pb push_back
void Kadane(vect<ll> &v, ll n) {
    ll max_sum = LLONG_MIN;
    ll curr_sum = 0;

    ll start = 0, end = 0, t_start = 0;

    for (ll i = 0; i < n; i++) {
        curr_sum += v[i];

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = t_start;
            end = i;
        }

        if (curr_sum < 0) {
            curr_sum = 0;
            t_start = i + 1;
        }
    }

    cout << max_sum << "\n";
}

int main() {
    freopen("DOANCONm.inp" , "r" , stdin);
    freopen("DOANCONm.out" , "w" , stdout);
    int n; 
    cin >> n;
    vect<ll> v;
    for (int i = 0; i < n; i++) {
        ll t ; cin >> t;
        v.pb(t);
    }
    Kadane(v, n);
    return 0;
}
