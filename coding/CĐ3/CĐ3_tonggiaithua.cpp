#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    long long temp=1;
    long long ans=0;
    for (int i=1; i<=n; i++){
        temp*=i;
        ans += temp;
    }
    cout << ans;
}