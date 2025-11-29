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
bool prime_check(ll n){
    if (n<2) return false;
    if (n==2) return true;
    for (int i=2 ; i*i <n ; i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
void solve(str n){
    ll temp=0;
    for (const char &i : n){
        ll t=i-'0';
        if (!prime_check(t)){
            cout << "NO";
            return;
        }
        temp+=t;
    }
    if (prime_check(temp)){
        cout << "YES";
    }
    else cout << "NO";
    return;
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    str n; cin >> n; solve(n);
    return 0;
}