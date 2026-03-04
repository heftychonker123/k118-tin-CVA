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


int main(){
    ll n,t ; cin >> n >> t;
    __int128 res=1;
    while(n--){
        ll temp ; cin >> temp;
        res *= temp%t;
        res %=t;
    }
    cout << (long long)res << "\n";
}