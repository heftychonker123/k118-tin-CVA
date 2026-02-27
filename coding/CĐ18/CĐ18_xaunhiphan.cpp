#include <bits/stdc++.h>
using namespace std;
#define filename "xaunhiphan"
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
str sinh(str s){
    ll i=s.size()-1;
    while (i>-1 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if (i>=0) s[i] = '1';
    return s;
}
void solve(){
    str s ; cin >> s;
    cout << sinh(s) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}