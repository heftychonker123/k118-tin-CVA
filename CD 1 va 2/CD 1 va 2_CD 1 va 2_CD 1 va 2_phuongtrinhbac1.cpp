#include <bits/stdc++.h>

using namespace std;

int main(){
    long double a,b; cin >> a >> b;
    if (a==0){
        if (b==0) cout << "VO SO NGHIEM";
        else cout << "VO NGHIEM";
    }
    else if (b==0) cout << "0.00";
    else cout << setprecision(2) << fixed << -1.00 * double(b/a);
    return 0;
}
