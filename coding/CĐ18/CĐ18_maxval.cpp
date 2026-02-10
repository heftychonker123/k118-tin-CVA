#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vect vector

ll calculate(vect<ll> &operands , str &s){
    ll res = operands[0];
    for (int i=1; i<4; i++){
        char op = s[i-1];
        ll curr = operands[i];
        if (op == '1') {
            if (curr == 0) return -numeric_limits<ll>::infinity();
            res /= curr;
        } else {
            res *= curr;
        }
    }
    return res;
}

void solve(){
    vect<ll> v(4);
    for (int i=0; i<4; i++) cin >> v[i];

    str s(3, '0');
    ll res = -numeric_limits<ll>::infinity();

    while (true){
        res = max(res, calculate(v, s));
        ll i = 2; 
        while (i > -1 && s[i] == '1') i--;
        if (i == -1) break;
        s[i] = '1';
        for (int j=i+1; j<3; j++) s[j] = '0';
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
