#include <bits/stdc++.h>
using namespace std;
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
ll factorial(ll a){
    ll res=1;
    for (int i=1 ; i<=a ; i++){
        res*=i;
    }
    return res;
} 
void solve(ll a , ll b){
    ll t = min(a,b);
    cout << factorial(t) << "\n";
    return;
}

int main(){
    ll a,b ; cin >> a >> b;
    solve(a,b);
    return 0;
}