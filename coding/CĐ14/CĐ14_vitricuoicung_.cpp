#include <bits/stdc++.h>
using namespace std;
#define filename "vitricuoicung_"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n,x ; cin >> n >> x;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    auto it = upper_bound(v.begin() , v.end() , x);
    if (it!=v.begin()){
        it--;
        if (*it==x){
            cout << it-v.begin() << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    else{
        cout << "-1\n";
    }
    return 0;
}