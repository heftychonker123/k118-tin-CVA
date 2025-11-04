#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >>n;
    long long a=1,b=1;
    if (n==1) cout << 1;
    else{
        cout << "1 " << "1 ";
        for (int i=0; i<n-2 ; i++){
            int c=a+b;
            cout << c << " ";
            b=a; a=c;
        }
    }
    return 0;
}