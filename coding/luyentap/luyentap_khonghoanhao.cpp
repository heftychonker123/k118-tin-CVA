#include <bits/stdc++.h>
using namespace std;
#define filename "khonghoanhao"
#define ll long long

void IO(){
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
bool check(ll a){
    ll sigma = 1;
    ll temp = a;
    for (ll i = 2; i * i <= temp; i++){
        if (temp % i == 0){
            ll sum = 1;
            ll power = 1;
            while (temp % i == 0){
                temp /= i;
                power *= i;
                sum += power;
            }
            sigma *= sum;
        }
    }
    if (temp > 1) sigma *= (1 + temp);
    return sigma > 2 * a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll a,b ; cin >> a >> b;
    ll cnt = 0;
    for (int i=a ; i<=b ; i++){
        if (check(i)) cnt ++;
    }
    cout << cnt << "\n";
    return 0;
}