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
    sstream ss(n);
    str temp;
    vect<str> num;
    while (ss >> temp){
        num.pb(temp);
    }
    str ans = "";
    sort(num.begin(), num.end());
    for (const str &i : num){
        ans += i;
    }
    cout << ans << endl;
}

int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}