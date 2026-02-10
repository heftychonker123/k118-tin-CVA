#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define str string

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    str s; cin >> s;

    vect<ll> prefCapital(n+1,0), prefNormal(n+1,0), prefNumber(n+1,0);

    for (int i=0 ; i<n ; i++){
        prefCapital[i+1] = prefCapital[i] + isupper(s[i]);
        prefNormal[i+1] = prefNormal[i] + islower(s[i]);
        prefNumber[i+1] = prefNumber[i] + isdigit(s[i]);
    }

    ll res=0;
    for (int i=0 ; i<n ; i++){
        ll smallest_sumstring = -1;
        ll l=5, r=n-i;
        while (l<=r){
            ll m = (l+r)/2;
            ll cntCapital = prefCapital[i+m] - prefCapital[i];
            ll cntNormal  = prefNormal[i+m] - prefNormal[i];
            ll cntNumber  = prefNumber[i+m] - prefNumber[i];
            if (cntNumber>=1 && cntNormal>=1 && cntCapital>=1){
                smallest_sumstring = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (smallest_sumstring != -1) {
            res += (n - i - smallest_sumstring + 1);
        }
    }

    cout << res << "\n";
}
