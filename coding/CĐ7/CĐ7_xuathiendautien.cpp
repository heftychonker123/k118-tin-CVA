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



void solve(str n){
    umap<char , ll > freq;// every element is (char, frequency)
    for (const char &i : n){
        freq[i]++;
    }
    ll temp=1;
    for (const char &i : n){
        if (freq[i]==1){
            cout << temp << "\n";
            return ;
        }
        temp++;
    }
    cout << -1 << "\n";
    return;
}



int main(){
    freopen("xuathiendt.inp" , "r" , stdin);
    freopen("xuathiendt.out" , "w" , stdout);
    ll n ; cin >> n;
    for (int tc=0 ; tc<n ; tc++){
        str s ; cin >> s;
        solve(s);
    }
    return 0;
}