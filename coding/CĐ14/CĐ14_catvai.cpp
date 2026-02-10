#include <bits/stdc++.h>
using namespace std;
#define filename "tknp_catvai"
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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,k ; cin >> n >> k;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    ll left = 1 , right = *max_element(v.begin() , v.end());
    ll res=llmin;
    while (left<=right){
        ll mid = (left+right)/2;
        ll cnt=0;
        for (const ll &i : v){
            cnt += i/mid;
        }
        if (cnt==k){
            res = max(res,mid);
            left = mid+1;
        }
        else if (cnt<k){
            right = mid-1;
        }
        else if (cnt>k){
            left=mid+1;
        }
    }
    if (res == llmin) cout << "0\n";
    else cout << res;
    return 0;
}