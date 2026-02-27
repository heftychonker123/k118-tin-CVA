#include <iostream>
using namespace std;

int main(){
    int n,x; cin >> x >>n;
    long long ans=1;
    for (int i=0; i<n; i++){
        ans*=x;
    }
    cout << ans;
}