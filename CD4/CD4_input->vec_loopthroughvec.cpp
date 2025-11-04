#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector <int> v={};
    for (int i=0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    
    for (const int & i : v){
        cout << i;
    }
    return  0;
}