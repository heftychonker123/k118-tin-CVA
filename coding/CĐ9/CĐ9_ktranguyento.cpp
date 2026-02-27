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

void solve(ll n){
    if (n<2) {
        cout << "NO";
        return;
    }
    if (n==2){
        cout << "YES";
        return;
    }
    for (int i=2 ; i*i <= n ; i++){
        if (n%i == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    return;
}

int main(){
    int n; cin >> n;
    solve(n);
}