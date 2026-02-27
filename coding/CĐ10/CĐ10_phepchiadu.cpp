#include <bits/stdc++.h>
using namespace std;
#define filename "phepchiadu"
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
int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str a; ll b;
    cin >> a >> b;
    ll re = 0;
    for (char c : a) {
        re = (re * 10 + (c - '0'))%b;
    }
    cout << re;
}