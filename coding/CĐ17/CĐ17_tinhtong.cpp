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
void traverse(str n , ll &index , ll &oddsum , ll &evensum){
    if (index == n.size()) return;
    else{
        ll t = (n[index] - '0');
        if (t%2 == 0) evensum += t;
        else oddsum += t;
        index ++ ;
        traverse(n,index,oddsum , evensum);
    }
}
void solve(){
    str n ; cin >> n;
    ll index = 0;
    ll oddsum = 0;
    ll evensum = 0;
    traverse(n , index , oddsum , evensum);
    cout << evensum << " " << oddsum;
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