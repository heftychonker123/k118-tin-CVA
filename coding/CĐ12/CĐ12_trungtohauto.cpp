#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define str string

ll precedence(char i){
    if (i=='-' || i=='+') return 1;
    if (i=='/' || i=='*') return 2;
    return 0;
}

void solve(){
    str n; cin >> n;
    str res = "";
    stack<char> st;

    for (int i=0; i<n.size(); i++){
        if (isalnum(n[i])){ 
            res += n[i]; 
        }
        else if (n[i] == '('){
            st.push(n[i]);
        }
        else if (n[i] == ')'){
            while (!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            ll curr = precedence(n[i]);
            while (!st.empty() && precedence(st.top()) >= curr){
                res += st.top();
                st.pop();
            }
            st.push(n[i]);
        }
    }

    while (!st.empty()){
        res += st.top();
        st.pop();
    }

    cout << res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
