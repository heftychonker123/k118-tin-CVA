#include <bits/stdc++.h>
using namespace std;
#define filename "phanhoach"
#define ll long long
#define str string
void inkq(str sub){
    for (auto i = sub.begin() ; i!=sub.end()-1 ; i++) cout << *i << "+";
    cout << *sub.rbegin() << "\n";
}
void phantich(ll n , ll end , str sub = "" ){
    if (n==0) {
        inkq(sub);
        return;
    }
    if (n<0) return;
    for (int i= end ; i>0 ; i--){
        phantich(n-i , i , sub + to_string(i) );
    }
    return;
}
void solve(){
    ll n ; cin >> n;
    phantich(n , n);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}