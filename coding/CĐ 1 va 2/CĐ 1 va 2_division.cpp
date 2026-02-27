#include <bits/stdc++.h>
using namespace std;

int main(){
    float a,b;cin >> a >> b;
    cout << floor(a/b)<< endl;
    cout << setprecision(3)<<fixed<< 1.000 * double(a/b)<<endl;
    return 0;
}