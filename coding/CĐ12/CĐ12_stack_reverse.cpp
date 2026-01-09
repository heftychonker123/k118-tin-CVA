#include <bits/stdc++.h>
using namespace std;
#define filename "innguoc"
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
    stack<ll> st;
    while (n--){
        ll t ; cin >> t ; st.push(t);
    }
    while(!st.empty()){
        cout << st.top() << "\n"; st.pop();
    }
    return;
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}