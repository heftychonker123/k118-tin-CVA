#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        int n; cin >> n;
        vector <long long> v={};
        vector <long long> y={};
        for (int i=0; i<n ; i++){
            long long t; cin >> t;
            if (t==0) v.push_back(t);
            else y.push_back(t);
        }
        for (const long long i:v) cout << i << " ";
        for (const long long i:y) cout << i << " ";
        cout << endl;
    }
    return 0;
}