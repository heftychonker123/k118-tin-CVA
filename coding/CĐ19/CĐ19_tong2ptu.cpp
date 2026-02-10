#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,s ; cin >> n >> s;
    ll a[n]; for (int i=0 ; i<n ; i++) cin >> a[i];
    ll i=0,j=n-1;
    sort(a , a+n);
    while (i<j){
        if (a[i]+a[j]==s){
            cout << "YES";
            return;
        }
        else if (a[i] + a[j]<s) i++;
        else j--;
    }
    cout << "NO";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}