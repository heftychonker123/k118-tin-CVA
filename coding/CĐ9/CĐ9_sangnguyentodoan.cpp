#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve(ll n, ll a) {
    vect<bool> primality(n+1 , 1);
    primality[0]=false;
    primality[1]=false;
    for (int p=0 ; p<n+1 ; p++){
        if (primality[p]){
            for (int i=p*p ; i<=n ; i+=p){
                primality[i]=false;
            }
        }
    }
    for (int i=a ; i<n+1 ; i++){
        if (primality[i]){
            cout << i << " ";
        }
    }
    return;
}

int main() {
    ll a,n; cin >> a >> n;
    solve(n,a);
    return 0;
}
