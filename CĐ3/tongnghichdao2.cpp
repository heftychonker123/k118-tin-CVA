#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long double ans=0;
    for (double i=1; i<=n; i++) ans+=1/i;
    cout << setprecision(3) << fixed << ans/5;
}