#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    freopen("emux.inp" , "r" , stdin);
    freopen("emux.out" , "w" , stdout);
    long double x;
    long double m;
    cin >> x >> m;
    long double temp1=1;
    long double temp2=0;
    long double ans=0;
    while (temp1>m){
        ans+=temp1;
        temp2+=1;
        temp1*= x/temp2;
    }
    ans+=temp1;
    cout << fixed << setprecision(5) << ans;
}
