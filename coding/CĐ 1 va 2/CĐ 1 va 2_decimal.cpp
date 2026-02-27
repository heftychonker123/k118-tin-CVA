#include <bits/stdc++.h>
using namespace std;

int main(){
    long double N; cin >>N;
    long long p=floor(N);
    cout << p << endl;
    cout <<setprecision(3)<<fixed<< abs(N- p)<<endl;
    return 0;
}