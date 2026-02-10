#include <bits/stdc++.h>
using namespace std;
#define filename "xaukytu"
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
    char C ; ll n ; cin >> C >> n;
    str start = "" ; for (int i=0 ; i<n ; i++) start += 'A';
    while (true){
        cout << start << "\n";
        ll i = n-1;
        while (i>-1 && start[i] == C) i--;
        if (i==-1) break;
        start[i] = (char) (start[i] + 1);
        for (int j=i+1 ; j<n ; j++) start[j] = 'A';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}