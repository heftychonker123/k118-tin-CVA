#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
    while (a!=0 && b!=0){
        if (a>b){
            a=a%b;
        }
        else if (a==b) return a;
        else b=b%a; 
    }
    return a+b;
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}
int main(){
    int m,n ; cin >> m >> n;
    long long t=lcm(m,n);
    for (int i=t ; i<m*n ; i+=t){
        cout << i << " ";
    }
    cout << m*n ;
    return 0;
}