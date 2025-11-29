#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1,x2,y1,y2;
    cin >>x1>>x2;
    cin >> y1 >> y2;
    long long ans=(x1-y1)*(x1-y1)+(x2-y2)*(x2-y2);
    cout << setprecision(2)<<fixed<< sqrt(ans);
}
