#include <bits/stdc++.h>
using namespace std;
#define filename "capsotonglonhonk"
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

ll upper_bound(vect<ll> &v , ll length , ll start , ll value){
    ll left = start+1 , right = length-1;
    ll res=length;
    while (left<=right){
        ll mid = (left+right)/2;
        ll t = v[mid] + v[start];
        // If sum>value, search the left(reduce the value)
        if (t > value){
            res = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return res;
}


int main(){
    int n,k ; cin >> n >> k;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll res=0;
    for (int i=0 ; i<n ; i++){
        ll t = upper_bound(v,n,i,k);
        res += (n-t);
    }
    cout << res << "\n";
    return 0;
}