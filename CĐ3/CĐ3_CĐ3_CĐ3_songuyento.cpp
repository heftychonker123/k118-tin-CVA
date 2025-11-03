#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    long a = sqrt(n);
    int ans=1;
    if (n==2) cout << 1;
    else{
        for (int i=2 ; i<=a+1 ; i++){
            if (n%i==0){
                ans=0;
                break;
            }
        }
        cout << ans;
    }
    return 0;
}