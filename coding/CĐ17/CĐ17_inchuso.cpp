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
void traverse(str n , ll &index){
    if (index == n.size()) {
        cout << "\n";
        return;
    }
    else{
        cout << n[index] << " ";
        index++;
        traverse(n , index);
    }
}
void reverse_traverse(str n , ll &index){
    if (index == 0) {
        cout << "\n";
        return;
    }
    else{
        cout << n[index-1] << " ";
        index--;
        reverse_traverse(n , index);
    }
}
void solve(){
    str n ; cin >> n;
    ll index = 0;
    traverse(n , index);
    reverse_traverse(n, index);
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