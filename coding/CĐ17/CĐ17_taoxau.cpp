#include <bits/stdc++.h>
using namespace std;
#define filename "TAOXAU"
#define ll long long
#define str string
#define vect vector
void permute(ll n , str sub , ll idx=1){
    if (idx == n){
        cout << sub << "\n";
        return;
    }
    if (sub.back() == 'A'){
        permute(n , sub+'A' , idx+1);
        permute(n , sub+'B' , idx+1);
    }
    else permute(n , sub+'A' , idx+1);
}
void solve(){
    ll n ; cin >> n;
    permute(n , "A");
    permute(n,"B");
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