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

void solve(str n){
    ll odd=0 , even=0;
    for (int i=0 ; i<n.size() ; i+=2){
        odd += n[i]-'0';
    }
    for (int i=1 ; i<n.size() ; i+=2){
        even += n[i] - '0';
    }
    if ((odd-even)%11==0) cout << "YES";
    else cout << "NO";
    return;
}

int main(){
    str n ; cin >> n;
    solve(n);
    return 0;
}