#include <bits/stdc++.h>
using namespace std;
#define filename "list"
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
bool check(str n){
    for (int i=0 ; i<n.size()-2 ; i++){
        vect<char> substring = {n[i] , n[i+1] , n[i+2]};
        sort(substring.begin() , substring.end());
        if (substring == vect<char>{'1' , '2' , '3'}){
            return true;
        }
    }
    return false;
}
bool check_distinct(str n){
    map<char,ll> freq;
    for (const char i : n) freq[i]++;
    for (auto [key,value]: freq){
        if (value>1) return false;
    }
    return true;
}
void solve(){
    ll cnt=0;
    for (int i=1e4 ; i<1e5 ; i++){
        if (check(to_string(i)) && check_distinct(to_string(i))){
            cnt++;
        }
    }
    cout << cnt;
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