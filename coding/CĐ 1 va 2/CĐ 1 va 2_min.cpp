#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a; cin >>a;
    long long b; cin >>b;
    long long c; cin >>c;
    long long d; cin >>d;
    cout << max(a,b)<<endl;
    cout << max({a,b,c})<<endl;
    cout << min({a,b,c,d})<<endl;
    return 0;
}