#include <bits/stdc++.h>
using namespace std;
#define filename "nhiphan5"
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
    ll res = 0;
    int pos = 0;

    for (int i = n.size() - 1; i >= 0; i--, pos++){
        ll z = 0;
        if (pos % 4 == 0) z = 1;
        else if (pos % 4 == 1) z = 2;
        else if (pos % 4 == 2) z = 4;
        else if (pos % 4 == 3) z = 3;

        res += (n[i] - '0') * z;
        res %= 5;
    }

    if (res == 0) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str n ; getline(cin,n);
    solve(n);
    return 0;
}