#include <bits/stdc++.h>
using namespace std;
#define filename "bmbr"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)
void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}


int main(){
    IO();
    ll n,k ; cin >> n >> k;
    vect<ll> v(n); for(int i=0 ; i<n ; i++) cin >> v[i];
    vect<ll> prefix_length(n+1 , 0) , suffix_length(n+1,0);
    FOR(i , 1 , n+1){
        prefix_length[i] = (v[i-1]== 1 ? prefix_length[i-1]+1 : 0);
    }
    FOR_r(i , n-1 , -1){
        suffix_length[i] = (v[i] == 1 ?suffix_length[i+1]+1 : 0);
    }
    ll res = k;
    FOR(i , 0 , n-k+1){
        ll length = k;
        length += prefix_length[i];
        length += suffix_length[i+k];
        res = max(res , length);
    }
    cout << res;
    return 0;
}