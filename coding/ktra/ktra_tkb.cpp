#include <bits/stdc++.h>
using namespace std;
#define filename "tkb"
#define ll long long
#define vect vector

ll m,n;

struct Point{
    ll x; 
    ll y; 
    ll value;
    Point(ll x, ll y , ll value): x(x) , y(y) , value(value){};
};
void dijikstra(ll x, ll y , vect<vect<ll>> &board , vect<vect<bool>> &visited){
    queue<pair<ll,ll>> q;
    q.push({x,y});
    visited[x][y] = true;
    while (!q.empty()){

    }
}

void solve(){}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}