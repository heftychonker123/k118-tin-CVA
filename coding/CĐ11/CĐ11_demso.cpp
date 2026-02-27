#include <bits/stdc++.h>
using namespace std;
#define filename "demso"
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
    ll a,b ; cin >> a >> b;
    vect<ll> x(a);
    for (int i=0 ; i<a ; i++) cin >> x[i];
    umap<ll,ll> freq;
    for (int i=0 ; i<b ; i++){
        ll t;cin>>t;freq[t]++;
    }
    for (const ll &i : x){
        cout << freq[i] << " ";
    }
    cout << "\n";
    return 0;
}