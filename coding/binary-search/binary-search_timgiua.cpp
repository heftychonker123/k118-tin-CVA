#include <bits/stdc++.h>
using namespace std;
#define filename "bai1"
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

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll l,r ; cin >> l >> r;
    ll t = (l*(l-1) + r*(r+1))/2;
    ll smallestDiff = LLONG_MAX , res=0;
    while (l<=r){
        ll m = l + (r-l)/2;
        if (abs(m*(m+1) - t) < smallestDiff){
            smallestDiff = abs(m*(m+1) - t);
            res = m;
        }
        if (m*(m+1)>t) r = m-1;
        else l = m+1;
    }
    cout << res << "\n";
    return 0;
}