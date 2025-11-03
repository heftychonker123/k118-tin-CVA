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
    umap<char,int> freq;
    for (const char &i : n){
        char t=tolower(i);
        freq[t]++;
    }
    if (freq.size()==26){
        cout << "YES";
    }
    else cout << "NO";
    return;
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    str n ; cin >> n;
    solve(n);
    return 0;
}