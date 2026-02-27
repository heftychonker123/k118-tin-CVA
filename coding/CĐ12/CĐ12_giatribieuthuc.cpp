#include <bits/stdc++.h>
using namespace std;
#define filename "giatribieuthuc"
#define ll long long
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
    str n ; cin >> n;
    stack<ll> st;
    for (int i=0 ; i< n.size() ; i++){
        char curr = n[i];
        if (isdigit(curr)){
            st.push(curr-'0');
        }
        else{
            ll op1 = st.top() ; st.pop();
            ll op2 = st.top() ; st.pop();
            ll results;
            if (curr == '-'){
                results = op2-op1;
            }
            if (curr == '+'){
                results = op1+op2;
            }
            if (curr == '*'){
                results = op1*op2;
            }
            if (curr == '/'){
                results = op2/op1;
            }
            st.push(results);
        }
    }
    cout << st.top();
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