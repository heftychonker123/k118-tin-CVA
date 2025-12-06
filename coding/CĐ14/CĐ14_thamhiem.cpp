#include <bits/stdc++.h>
using namespace std;
#define filename "thamhiem"
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

void solve(vect<ll> v , ll length){
    sort(v.rbegin() , v.rend());
    ll res=0;
    for (int i=0 ; i<length ; i++){
        res+=max((ll)0,v[i]-i);
    }
    cout << res << "\n";
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    int n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++){
        cin>>v[i];
    }
    solve(v,n);
    return 0;
}