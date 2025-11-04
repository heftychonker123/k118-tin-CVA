#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n ; i++) cin >> v[i];
    int temp=v[0];
    for (int i=1; i<n ; i++){
        temp=gcd(temp,v[i]);
    }
    cout << temp;
}