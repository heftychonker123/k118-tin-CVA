#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
//class







//function
ll count(ll n, ll k) {
    if (n == 0) return k == 0 ? 1 : 0;
    ll ans = 0;
    while (n > 0) {
        ll t = n % 10;
        if (t == k) ans++;
        n /= 10;
    }
    return ans;
}







//initialization code
int main(){
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        int n , k; cin >> n >> k;
        ll ans=0;
        for (int i=0 ; i<n ; i++){
            ll z; cin >> z;
            ans+=count(z,k);
        }
        cout << ans << "\n";
    }
    return 0;
}