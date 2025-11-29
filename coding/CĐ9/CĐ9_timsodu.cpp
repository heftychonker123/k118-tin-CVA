#include <bits/stdc++.h>
using namespace std;
#define filename "timsodu"
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

void solve(const str &n){
    ll t;
    if (n.size() < 2){
        t = n[0] - '0';
    } else {
        // Lấy 2 chữ số cuối cùng
        t = (n[n.size()-2] - '0') * 10 + (n[n.size()-1] - '0');
    }

    if (t % 4 == 0){
        cout << 4 << "\n";
    } else {
        cout << 0 << "\n";
    }
}


int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str n; getline(cin,n);
    solve(n);
    return 0;
}