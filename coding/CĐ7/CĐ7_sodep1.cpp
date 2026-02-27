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
bool check_not_decreasing(str n){
    ll length=n.size();
    for (int i=1; i<length ; i++){
        if (n[i]<n[i-1]){
            return false;
        }
    }
    return true;
}
bool check_not_increasing(str n){
    ll length=n.size();
    for (int i=1; i<length ; i++){
        if (n[i]>n[i-1]){
            return false;
        }
    }
    return true;
}
void solve(str n){
    bool i=check_not_decreasing(n);
    bool d=check_not_increasing(n);
    if (i || d) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    str n ; cin >> n; solve(n);
    return 0;
}