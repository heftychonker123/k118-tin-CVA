#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sieve(int n){
    vector<bool> primality(n+1, true);
    primality[0] = primality[1] = false;
    
    for (int i = 2; i <= n; i++){
        if (primality[i]){
            for (long long j = (long long)i * i; j <= n; j += i){
                primality[j] = false;
            }
        }
    }
    
    vector<int> prime;
    for (int i = 2; i <= n; i++){
        if (primality[i]) prime.push_back(i);
    }
    return prime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> prime = sieve(2*1e6);
    
    for (const int &i : v){
        if (i == 0 || i == 1) {
            cout << i << ' ';
        } else {
            auto it = lower_bound(prime.begin(), prime.end(), i);
            if (it == prime.end()) it--;
            else if (it != prime.begin() && *it != i) it--;
            cout << *it << ' ';
        }
    }
    return 0;
}