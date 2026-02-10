#include <bits/stdc++.h>
using namespace std;
#define filename "hoanvi"
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
void solve(){
    ll n ; cin >> n;
    vect<str> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    do{
        for (const auto &i : v) cout << i << " ";
        cout << "\n";
    } while (next_permutation(v.begin() , v.end()));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}