#include <bits/stdc++.h>
using namespace std;


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
    int n ; cin >> n ;
    vector<long double> v(n);
    long double ans=0;
    for (int i=0; i<n ; i++) cin >> v[i];
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n ; j++){
            long long t=v[i]+v[j];
            if (check_prime(t)) ans++;
        }
    }
    cout << ans;
}
