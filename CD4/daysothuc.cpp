#include <bits/stdc++.h>
using namespace std;

int main(){
    long double n; cin >> n;
    long double sum = 0;
    vector<long double> ans(5,0);
    for (long long i = 0; i < n; i++){
        long double t; cin >> t;
        ans[0]+=t;
        if (i%2==0) ans[4]+=t;
        if (i%2!=0) ans[3]+=t;
        if (t>0) ans[2]+=t;
        if (t<0) ans[1]+=t;
    }
    cout << fixed << setprecision(2);
    for (const long double i:ans){
        cout << i << " ";
    }
}
