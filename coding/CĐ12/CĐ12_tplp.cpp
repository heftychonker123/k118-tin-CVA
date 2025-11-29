#include <bits/stdc++.h>
using namespace std;
#define filename "tplp"
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
    stack<char> st;
    while(n>0){
        ll t=n%16;
        if (t>=10){
            st.push('A' + t-10);
        }
        else{
            st.push('0' + t);
        }
        n/=16;
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