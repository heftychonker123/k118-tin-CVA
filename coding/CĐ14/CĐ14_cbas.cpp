#include <bits/stdc++.h>
using namespace std;
#define filename "cbas"
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
    ll n,s ; cin >> n >> s;
    vect<pair<ll,ll>> m;
    while (n--){
        ll a,b ; cin >> a >> b;
        m.pb({a,b});
    }
    sort(m.begin() , m.end() , [&](pair<ll,ll> a , pair<ll,ll> b){
        if (a.first==b.first) return a.second>b.second;
        return a.first<b.first;
        }
    );
    for (auto i:m){
        if (s>i.first){
            s+=i.second;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}