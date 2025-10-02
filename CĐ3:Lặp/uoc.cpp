#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    long long ans=0;
    for (int i=1; i<=n; i++){
        if (n%i==0) ans+=1;
    }
    cout << ans << endl;
    for (int i=1; i<=n; i++){
        if (n%i==0) cout << i << " ";
    }
}