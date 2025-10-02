#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n; cin >> n;
    long a=sqrt(n);
    long long ans=0;
    for (int i=1; i<=a; i++){
        if (n%i==0){
            ans+=i;
            if (n/i!=i){
                ans+=n/i;
            }
        }
    }
    cout << (ans==2*n);
}