#include <bits/stdc++.h>
using namespace std;
#define filename "tongchuso"
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
ll num(ll n , ll choice){
    stack<ll> st;
    if (n==0) return 0;
    while (n!=0){
        st.push(n%10);
        n/=10;
    }
    if (choice == 1){
        ll sum=0;
        while (!st.empty()){
            sum+= st.top() ; st.pop();
        }
        return sum;
    }
    if (choice == 2){
        return st.size();
    }
    if (choice == 3){
        return st.top();
    }
}
void solve(){
    ll n ; cin >> n;
    cout << num(n,3);
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