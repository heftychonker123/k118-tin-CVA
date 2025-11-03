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
vect<str> split(str n){
    sstream ss(n);
    str t;
    vector<str> v={};
    while (getline( ss , t ,' ')){
        if (not t.empty()) v.pb(t);
    }
    return v;
}
void solve(str n){
    vector<str> v=split(n);
    if (v.size()<2) {
        cout << v[0];
    }
    else{
        cout << v[0] << endl;
        for (auto i=v.begin()+1 ; i < v.end()-1 ; i++){
            cout << *i << " ";
        }
        cout << endl;
        cout << *(v.end()-1) << endl;
    }
    return;
}
int main(){
    freopen("tachhdt.inp" , "r" , stdin);
    freopen("tachhdt.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}