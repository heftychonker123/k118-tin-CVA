#include <bits/stdc++.h>
using namespace std;
#define filename "catday"
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

bool check(vect<ll> n , ll length , ll k){
    ll temp = 0;
    for (const ll &i : n){
        temp += (i/length);
    }
    return temp>=k;
}

int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n,k ; cin >> n >> k;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll left = 1, right = *max_element(v.begin() , v.end())+1;
    ll res=-1;
    while (left <= right){
        ll mid = (left+right)/2;
        if (check(v,mid,k)){
            res = max(res,mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    if (res==-1) cout << 0 << "\n";
    else cout << res << "\n";
    return 0;
}