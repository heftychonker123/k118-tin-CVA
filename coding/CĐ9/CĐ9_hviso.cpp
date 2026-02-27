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
bool check(str n){
    ll temp=0;
    bool t=false;
    for (const char &i:n){
        if (i=='0') t=true;
        temp += i-'0';
    }
    return (t && temp%3==0);
}
void solve(str n){
    if (!check(n)){
        cout << -1 << "\n";
        return;
    }
    sort(n.rbegin() , n.rend());
    cout << n << "\n";
    return;
}

int main(){
    str n ; cin >> n;
    solve(n);
    return 0;
}