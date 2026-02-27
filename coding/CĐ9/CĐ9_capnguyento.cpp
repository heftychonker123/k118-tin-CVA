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

void solve(ll a , ll b){
    for (int i=a ; i<=b ; i++){
        for (int j=i+1 ; j<=b ; j++){
            if (gcd(i,j)==1){
                cout << i << " " << j << "\n";
            }
        }
    }
    return;
}

int main(){
    int a,b ; cin >> a >> b;
    solve(a,b);
    return 0;
}