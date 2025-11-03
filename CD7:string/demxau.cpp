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


void solve(str a, str b) {
    ll temp = 0;
    vect<ll> ans = {};
    while (temp <= b.size()) {
        ll pos = b.find(a, temp);
        if (pos != std::string::npos) {
            ans.pb(pos);
            temp = pos + 1;
        }
        else temp++;
    }
    cout << ans.size() << "\n";
    for (const ll &i : ans) cout << i+1 << " ";
}


int main(){
    freopen("demxau.inp" , "r" , stdin);
    freopen("demxau.out" , "w" , stdout);
    str a,b ; cin >> a; cin >> b;
    solve(a,b);
    return 0;
}