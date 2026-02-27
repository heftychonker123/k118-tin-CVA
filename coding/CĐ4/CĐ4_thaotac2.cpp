#include <bits/stdc++.h>
using namespace std;

bool check_prime(long long n){
    freopen("thaotac2.inp" , "r" , stdin);
    freopen("thaotac2.out" , "w" , stdout);
    if (n<2) return false;
    if (n==2) return true;
    else{
        bool ans=true;
        for (long i=2; i<=sqrt(n); i++){
            if (n%i==0){
                ans=false;
                break;
            }
        }
        return ans;
    }
}

int main(){
    int n; cin >> n;
    vector <int> v={};
    vector <int> prime={};
    vector <int> not_prime={};
    for (int i=0; i < n; i++){
        long t; cin >> t;
        v.push_back(t);
    }
    
    for (const int & i : v){
        if (check_prime(i)){
            prime.push_back(i);
        }
        else{
            not_prime.push_back(i);
        }
    
    }
    for (int i=0; i <prime.size(); i++){
        cout << prime[i] << " ";
    }
    for (int i = not_prime.size() - 1; i >= 0; i--) {
        cout << not_prime[i] << " ";
    }
    return  0;
}