#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vect<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    ll sum = 0;
    vect<ll> prefix(n+1, 0);
    for (int i=0; i<n; i++){
        sum += v[i];
        prefix[i+1] = sum;
    }

    if (sum % 3 != 0){
        cout << "-1\n";
        return 0;
    }

    ll target = sum / 3;
    ll x = -1, y = -1;

    for (int i=1; i<=n; i++){
        if (prefix[i] == target){
            x = i;
            break;
        }
    }

    for (int i=n-1; i>=0; i--){
        if (sum - prefix[i] == target){
            y = i;
            break;
        }
    }

    if (x == -1 || y == -1 || x >= y){
        cout << "-1\n";
    } else {
        cout << x << " " << y << "\n";
    }

    return 0;
}
