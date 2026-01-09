#include <bits/stdc++.h>
using namespace std;
#define filename "tongbinhphuong"
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
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    ll sum=0;
    for (int i=1 ; i<= n ; i+=2){
        sum+=(i*i);
    }
    cout << sum;
}