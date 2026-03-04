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
ll maxpos(str n , ll &index , ll &ans){
    if (index == n.size()-1) return ans;
    index++;
    if (n[index] > n[ans]){
        ans = index;
    }
    return maxpos(n , index , ans);
}
ll minpos(str n , ll &index , ll &ans){
    if (index == n.size()-1) return ans;
    index++;
    if (n[index] < n[ans]){
        ans = index;
    }
    return minpos(n , index , ans);
}
void solve(){
    str n ; cin >> n;
    ll index = 0LL;
    ll maxans = 0LL;
    ll minans = 0LL;
    ll maxres = maxpos(n , index , maxans);
    index = 0;
    ll minres = minpos(n,index,minans);
    cout << n[maxres] << " " << n[minres];
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