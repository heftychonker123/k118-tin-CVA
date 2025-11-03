#include <bits/stdc++.h>
using namespace std;
bool solve(vector<long long> a, vector<long long> b , int n){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=n-1 ; i>-1 ; i--){
        if (a[i]<=b[i]) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    vector <long long> a(n) , b(n);
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=0 ; i<n ; i++) cin >> b[i];
    if (solve(a,b,n)) cout << "Yes";
    else cout << "No";
}