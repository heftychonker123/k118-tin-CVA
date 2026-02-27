#include <bits/stdc++.h>
using namespace std;
#define filename "robot"
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
    str s ; getline(cin,s);
    stack<char> st;
    for (const char &i : s){
        if (i!=' ') st.push(i);
    }
    while (!st.empty()){
        cout << st.top(); st.pop();
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