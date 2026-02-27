#include <bits/stdc++.h>
using namespace std;
#define filename "quatang"
#define ll long long
#define str string
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    vect<ll> v(n) ; for (int i=0 ; i<n ; i++) cin >> v[i];
    str start = ""; for (int i=0 ; i<n ; i++) start += "0";
    ll res = LLONG_MAX;
    while (true){
        ll sub1 = 0 , sub2 = 0;
        for (int i=0 ; i<n ; i++){
            if (start[i] == '1') sub1 += v[i];
            else sub2 += v[i];
        }
        if (abs(sub1-sub2) < res) res = abs(sub1-sub2);
        ll i = n-1;
        while (i>-1 && start[i] == '1'){
            start[i] = '0';
            i--;
        }
        if (i==-1) break;
        start[i] = '1';
    }
    cout << res;
    return 0;
}