#include <bits/stdc++.h>
using namespace std;
#define filename "dayngoac"
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

void solve(str n){
    stack<char> st;
    for (const char &i : n){
        if (i=='('){
            st.push(i);
        }
        if (i==')'){
            if (st.empty()){
                cout << "NO";
                return;
            }
            st.pop();
        }
    }
    if (!st.empty()) cout << "NO";
    else cout << "YES";
    cout << "\n";
    return;
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    cin.ignore();
    str t ; getline(cin,t);
    solve(t);
    return 0;
}