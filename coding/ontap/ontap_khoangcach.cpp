#include <bits/stdc++.h>
using namespace std;
#define filename "Bai1"
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    str a,b ; cin >> a >> b;
    ll i=a.size()-1 , j=b.size()-1;
    ll res=0;
    while (i>-1 && j>-1){
        res += abs(a[i]-b[j]);
        i-- ; j--;
    }
    while (i>-1){
        res+= a[i]-'0';
        i--;
    }
    while (j>-1){
        res+= b[j]-'0';
        j--;
    }
    cout << res;
    return 0;
}