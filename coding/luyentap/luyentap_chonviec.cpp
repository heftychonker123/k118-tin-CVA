#include <bits/stdc++.h>
using namespace std;
#define filename "bai3"
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
bool comp(array<ll,3> a , array<ll,3> b){
    if (a[0] != b[0]) return a[0] < b[0];
    else if (a[1] != b[1]) return a[1] > b[1];
    else return a[2] < b[2];
}
int main(){
    IO();

    ll n,t; cin >> n >> t;
    vect<array<ll,3>> v(n);
    for (int i=0 ; i<n ; i++){
        v[i][2] = i;
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin() , v.end() , comp);
    vect<ll> order(n);
    ll currTime=0 , profit = 0;
    for (int i=0 ; i<n ; i++){
        auto curr = v[i];
        if (currTime < curr[0]) profit += curr[1];
        currTime+=t;
        order[curr[2]] = currTime;
    }
    for (const ll &i : order) cout << i << "\n";
    cout << profit << "\n";
    return 0;
}