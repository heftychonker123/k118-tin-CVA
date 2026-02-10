#include <bits/stdc++.h>
using namespace std;
#define filename "stack_basic"
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
    ll q; cin >> q;
    stack<ll> st;
    while (q--){
        ll query; cin >> query;
        switch(query){
            case 1:
                ll x ; cin >> x;
                st.push(x);
                break;
            case 2:
                if (!st.empty()){
                    cout << st.top() << "\n";
                }
                break;
            case 3:
                if (!st.empty()) st.pop();
                break;
            case 4:
                if (st.empty()) cout << "EMPTY";
                else cout << st.size();
                cout << "\n";
                break;
            case 5:
                if (st.empty()) cout << "YES";
                else cout << "NO";
                cout << "\n";
                break;
            case 6:
                if (!st.empty()){
                    vect<ll> v;
                    while (!st.empty()){
                        v.pb(st.top()) ; st.pop();
                    }
                    for (auto it = v.rbegin() ; it!=v.rend() ; it++){
                        cout << *it << " ";
                        st.push(*it);
                    }
                    cout << "\n";
                }
                else cout << "EMPTY\n";
                break;
            default:
                break;
        }
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