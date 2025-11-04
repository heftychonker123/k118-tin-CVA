#include <bits/stdc++.h>
using namespace std;
long long calc(string n){
    long long ans=0;
    for (char i:n){
        int t= i-'0';
        ans+=t;
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
    string n; cin >> n;
    long long t=calc(n);
    if (check_prime(t)) cout << "YES";
    else cout << "NO";
}