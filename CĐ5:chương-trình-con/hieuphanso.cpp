#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    long long a,b,c,d; cin >> a >> b;
    cin >> c >> d;
    long long t= a*d - c*b;
    long long m=b*d;
    long long p=abs(gcd(t,m));
    cout << t/p << "/" << m/p; 
}