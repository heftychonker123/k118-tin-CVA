#include <bits/stdc++.h>
using namespace std;
#define filename "loaibokytu"
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
    str s ; cin >> s;
    stack<char> st;
    for (const char &i : s){
        if (st.empty()) st.push(i);
        else{
            if (i==st.top()) st.pop();
            else st.push(i);
        }
    }
    vect<char> v;
    if (st.empty()) cout << "EMPTY";
    else{
        while(!st.empty()){
            v.pb(st.top()) ; st.pop();
        }
        for (auto i=v.rbegin() ; i!=v.rend() ; i++) cout << *i;
    }
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