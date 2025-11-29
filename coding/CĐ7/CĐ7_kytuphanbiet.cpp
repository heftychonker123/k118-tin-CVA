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
    umap<char , ll> freq;
    for (const char &i : n){
        if (i!=' '){
            char t=tolower(i);
            freq[t]++;
        }
    }
    cout << freq.size();
    return;
}
int main(){
    freopen("KITUKN.INP" , "r" , stdin);
    freopen("KITUKN.OUT" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}