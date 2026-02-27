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
bool check(ll n){
    if (n<2) return false;
    if (n==2) return true;
    else{
        for (int i=2; (i)*(i)<n ; i++){
            if (n%i==0) return false;
        }
        return true;
    }
}
void solve(str n){
    vect<ll> v={};
    str temp="";
    for (const char &i : n){
        if (isdigit(i)){
            temp+=i;
        }
        else{
            if (!temp.empty()){
                v.pb(stoi(temp));
                temp="";
            }
        }
    }
    if (!temp.empty()){
        v.pb(stoi(temp));
        temp="";
    }
    umap<ll , ll> freq;
    for (const ll &i : v){
        if (check(i)) freq[i]++;
    }
    ll ans=0;
    for (const auto &i : freq){
        ans+=i.first;
    }
    cout << ans << "\n";
}
int main(){
    freopen("tongnt.inp" , "r" , stdin);
    freopen("tongnt.out" , "w" , stdout);
    str n; getline(cin , n);
    solve(n);
    return 0;
}