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
bool check_div_p(str n, ll p){
    if (n.size()>2){
        str t = n.substr(n.size()-2,2);
        ll temp = stoi(t);
        if (temp%p==0) return true;
        else return false;
    }
    else{
        ll temp = stoi(n);
        if (temp%p==0) return true;
        else return false;
    }
}
bool check_div_3(str n){
    ll temp=0;
    for (const char &i : n){
        ll t = i-'0';
        temp+=t;
    }
    return (temp%3==0);
}
void solve(str n){
    if (check_div_3(n) && check_div_p(n,5)){
        cout << "YES";
    }
    else cout << "NO";
    return;
}
int main(){
    str n ; cin >> n;
    solve(n);
    return 0;
}