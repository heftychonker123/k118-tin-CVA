#include <bits/stdc++.h>
using namespace std;
#define filename "chusonhonhat"
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
bool traverse(str n , ll &index){
    if (index == n.size()) return true;
    else{
        if (n[index]%2==1) return false;
        index++;
        return traverse(n,index);
    }
}
void solve(){
    str n ; cin >> n;
    ll index = 0;
    if (traverse(n,index)) cout << "YES";
    else cout << "NO";
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}