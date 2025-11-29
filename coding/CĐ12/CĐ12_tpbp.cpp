#include <bits/stdc++.h>
using namespace std;
#define filename "tpbp"
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

void solve(ll n){
    stack<ll> st;
    while (n>0){
        st.push(n%8);
        n/=8;
    }
    while (!st.empty()){
        cout << st.top();
        st.pop();
    }
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    solve(n);
    return 0;
}