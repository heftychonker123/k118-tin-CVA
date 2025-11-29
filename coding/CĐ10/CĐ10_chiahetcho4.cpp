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
    if (n.size()>2){
        str t = n.substr(n.size()-2,2);
        ll temp = stoi(t);
        if (temp%4==0) cout << "YES";
        else cout << "NO";
    }
    else{
        ll temp = stoi(n);
        if (temp%4==0) cout << "YES";
        else cout << "NO";
    }
    return;
}

int main(){
    str n ; cin >> n;
    solve(n);
    return 0;
}