#include <bits/stdc++.h>
using namespace std;
#define filename "bitsop"
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n = 6;
    for (int x=1 ; x< (1<<n) ; x++){
        for (int i=0 ; i<n ; i++){
            cout << ((x>>i)&1);
        }
        cout << "\n";
    }
    return 0;
}