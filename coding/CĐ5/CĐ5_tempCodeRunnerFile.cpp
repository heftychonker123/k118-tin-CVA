#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> v(n,0);
    for (int i=0; i<n ; i++){
        long long t; cin >> t;
        if (t%2==0){
            v[0]++;
            v[2]+=t;
        }
        else {
            v[1]++;
            v[3]+=t;
        }
    }
    for (const i:v){
        cout << i << "\n";
    }
}