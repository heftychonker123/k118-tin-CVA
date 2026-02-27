#include <bits/stdc++.h>
using namespace std;
#define filename "sodep2"
#define ll long long

ll countBinaryNumbers(ll n) {
    if (n <= 1) return 0;
    
    string s = to_string(n);
    int len = s.length();
    ll count = 0;
    

    for (int i = 1; i < len; i++) {
        count += (1LL << (i - 1));
    }
    
    for (int i = 0; i < len; i++) {
        if (s[i] > '1') {
            if (i == 0) {
                count += (1LL << (len - i - 1));
            } else {
                count += (1LL << (len - i));
            }
            break;
        } else if (s[i] == '1') {
            if (i > 0) {
                count += (1LL << (len - i - 1));
            }
        }
    }
    
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        cout << countBinaryNumbers(n) << "\n";
    }
    
    return 0;
}