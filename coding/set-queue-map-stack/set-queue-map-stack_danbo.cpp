#include <bits/stdc++.h>
using namespace std;
#define filename "danbo"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n,k ; cin >> n >> k;
    queue<ll> q;
    q.push(n);
    ll res=0;
    while (!q.empty()){
        ll curr = q.front() ; q.pop();
        if ((curr-k)%2 == 0 && curr>k){
            q.push((curr+k)/2);
            q.push((curr-k)/2);
        }
        else res++;
    }
    cout << res << "\n";
    return 0;
}