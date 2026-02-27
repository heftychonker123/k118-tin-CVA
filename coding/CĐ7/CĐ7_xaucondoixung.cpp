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
void solve(str a, ll length) {
    ll ss_length = 1;

    for (ll i = 0; i < length; i++) {
        ll temp_ss_len_odd = 1;
        ll l = i - 1, r = i + 1;
        while (l >= 0 && r < length && a[l] == a[r]) {
            temp_ss_len_odd += 2;
            l--; r++;
        }

        ll temp_ss_len_even = 0;
        l = i, r = i + 1;
        while (l >= 0 && r < length && a[l] == a[r]) {
            temp_ss_len_even += 2;
            l--; r++;
        }

        ss_length = max(ss_length, max(temp_ss_len_odd, temp_ss_len_even));
    }

    cout << ss_length;
}
int main(){
    freopen("xaucondx.inp" , "r" , stdin);
    freopen("xaucondx.out" , "w" , stdout);
    ll n ; str a;
    cin >> n; cin >> a;
    solve(a,n);
    return 0;
}