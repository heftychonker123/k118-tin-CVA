#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("timmax.inp" , "r" , stdin);
    freopen("timmax.out" , "w" , stdout);
    int n; cin >> n;
    vector <int> v={};
    long long max=-100000001;
    for (int i=0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    
    for (int i=0; i<n; i++){
        if (v[i] > max){
            max=v[i];
        }
    }
    cout << max << endl;
    for (int i=0; i<n; i++){
        if (v[i] == max){
            cout << i+1 << " ";
        }
    }
    return  0;
}