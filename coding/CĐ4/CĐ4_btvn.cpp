#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN;
#define llmax LLONG_MAX;
#define pb push_back;
//initialization code
int main(){
    int n,t; cin >> n >> t;
    ll ans=0;
    vector<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin(),v.end());
    for (const ll i:v){
        if (t>=i){
            ans++;
            t+=i;
        }
        else{
            cout << ans;
            return 0;
        }
    }
    cout << n;
    return 0;
}