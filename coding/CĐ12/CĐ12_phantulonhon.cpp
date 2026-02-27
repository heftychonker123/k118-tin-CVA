#include <bits/stdc++.h>
using namespace std;
#define filename "phantulonhon"
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
    ll n ; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    stack<ll> st;
    vect<ll> res(n);
    for (int i=n-1 ; i>=0 ; i--){
        while (!st.empty() && st.top()<=v[i]){
            st.pop();
        }
        if (!st.empty()) res[i] = st.top();
        else res[i] = -1;
        st.push(v[i]);
    }
    for (const ll &i : res) cout << i << " ";
    return;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}