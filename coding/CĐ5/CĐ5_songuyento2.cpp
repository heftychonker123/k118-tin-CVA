#include <bits/stdc++.h>
using namespace std;
long calc_div(long long n){
    long ans=0;
    for (int i=1 ; i*i<=n ; i++){
        if (n%i==0){
            if (n/i!=i) ans+=2;
            else ans++;
        }
    }
    return ans;
}

bool check_prime(long long n){
    if (n<2) return false;
    if (n==2) return true;
    else{
        for (int i=2; (i-1)*(i-1) <= n; i++){
            if (n%i==0) return false;
        }
        return true;
    }
}
int main(){
    long long n; cin >> n;
    long t=calc_div(n);
    if (check_prime(t)) cout << "YES";
    else cout << "NO";
}