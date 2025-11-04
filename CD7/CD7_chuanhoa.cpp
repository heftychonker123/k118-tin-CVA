#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream // not sus name anymore
str standard(str n){
    n[0]=toupper(n[0]);
    for (stri i=n.begin()+1 ; i!=n.end() ; i++){
        *i = tolower(*i);
    }
    return n;
}
void solve(str n){
    sstream ss(n);
    str t;
    vector<str> v={};
    while (getline( ss , t ,' ')){
        if (not t.empty()) v.pb(t);
    }
    for (const str &i : v){
        str t = standard(i);
        cout << t << " ";
    }
}

int main(){
    freopen("CHUANHOA.inp" , "r" , stdin);
    freopen("CHUANHOA.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}