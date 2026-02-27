#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    string s; cin >> s;

    set<char> dis(s.begin(), s.end());
    ll total_distinct = dis.size();

    unordered_map<char,ll> freq;
    ll res = LLONG_MAX;
    ll l = 0;

    for (ll r = 0; r < n; r++) {
        freq[s[r]]++;

        while (freq.size() == total_distinct) {
            res = min(res, r - l + 1);
            freq[s[l]]--;
            if (freq[s[l]] == 0) {
                freq.erase(s[l]);
            }
            l++;
        }
    }

    cout << res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
