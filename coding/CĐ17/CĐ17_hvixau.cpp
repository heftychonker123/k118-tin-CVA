#include <bits/stdc++.h>
using namespace std;
#define filename "Hvxau"
#define ll long long
#define str string
void solve() {
    str n; 
    cin >> n;
    sort(n.begin() , n.end());
    cout << n << "\n";
    while (next_permutation(n.begin() , n.end())){
        cout << n << "\n";
    }
}
void IO(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //IO();
    solve();
    return 0;
}
