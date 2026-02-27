#include <bits/stdc++.h>
using namespace std;
#define filename "sernum"
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
    ll a,b ; cin >> a >> b;
    ll rem = a*10;
    ll cnt = 0;
    while ((rem+b)%89 != 0){
        cnt++;
        rem*=10 ; rem%=89;
    }
    ll num = a*10; for (int i=0 ; i<cnt ; i++) num*=10; num+=b;
    cout << num/89;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}