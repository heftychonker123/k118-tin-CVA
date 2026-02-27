#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector

void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<ll> a(n) , b(n);
    for (int i=0 ; i<n ; i++) cin >> a[i] >> b[i];
    sort(a.begin() , a.end());
    sort(b.rbegin() , b.rend());
    ll res=0;
    for (int i=0 ; i<n ; i++){
        if (!(a[i]==-1 && b[i]==-1)) res++;
    }
    cout << res;
    return 0;
}