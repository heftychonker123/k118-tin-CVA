#include <bits/stdc++.h>
using namespace std;
#define filename "timkiemnhiphan"
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
void bin(vect<ll> &v , ll x){
    ll left=0 , right=v.size()-1;
    while (left<=right){
        ll mid = (left+right)/2;
        if (v[mid]==x){
            cout << "YES\n";
            return;
        }
        else if (v[mid]>x){
            left = mid+1;
        }
        else if (v[mid]<x){
            right = mid-1;
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    ll n ; cin >> n;
    vect<ll> v(n);
    for (ll i=0 ; i<n ; i++) cin >> v[i];
    sort(v.rbegin() , v.rend());
    ll q ; cin >> q;
    while (q--){
        ll x ; cin >> x;
        bin(v,x);
    }
    return 0;
}