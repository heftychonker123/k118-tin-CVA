#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m; cin >> n >> m;
    int t=0;
    for (long double i=n; i<m; i*=1.1){
        t+=1;
    }
    cout << t;
}