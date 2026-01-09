#include <bits/stdc++.h>
using namespace std;
#define filename "418Ccf"
#define ll long long
#define str string
#define pb push_back
#define vect vector
void solve(){
    ll n ; cin >> n;
    str s ; cin >> s;
    ll q ; cin >> q;
    while (q--){
        ll m ; char c ; cin >> m >> c;
        vect<ll> ch(n+1 , 0);
        for (int i=1 ; i<=n ; i++){
            ch[i] = ch[i-1];
            if (s[i-1] != c) ch[i]++;
        }
        ll l=0;
        ll res = 0;
        for (int r=1 ; r<=n ; r++){
            while (ch[r] - ch[l] > m){
                l++;
            }
            res = max(res , r-l);
        }
        cout << res << "\n";
    }
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}