#include <bits/stdc++.h>
using namespace std;
#define filename "Nconxe"
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
ll t=1;
void nrook(ll n , vect<vect<bool>> &placement , vect<vect<ll>> place , ll row = 0){
    if (row==n){
        cout << t << "\n";
        for (const auto v: place){
            for (const ll i:v) cout << i << " ";
            cout << "\n";
        }
        t++;
        return;
    }
    for (int i=0 ; i<n ; i++){
        if (placement[row][i]){
            for (int j=row ; j<n ; j++){
                placement[j][i] = false;
            }
            place[row][i] = row+1;
            nrook(n,placement,place,row+1);
            for (int j=row ; j<n ; j++){
                placement[j][i] = true;
            }
            place[row][i] = 0;
        }
    }
}
void solve(){
    ll n ; cin >> n;
    vect<vect<bool>> placement(n , vect<bool>(n,true));
    vect<vect<ll>> place(n , vect<ll>(n,0));
    nrook(n , placement , place);
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    solve();
    return 0;
}