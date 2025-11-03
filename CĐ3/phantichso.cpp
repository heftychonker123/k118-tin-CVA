#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n; cin >>n;
    int ans=0;
    for (int i=sqrt(n); i>0; i--){
        if (n%i==0){
            ans=i;
            break;
        }
    }
    cout << ans << " " << n/ans;
}
