#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        int n; cin >> n;
        long long left_sum=0;
        long long right_sum=0;
        for (int i=1 ; i<n+1 ; i++){
            long long t; cin >> t;
            if (i<=n/2){
                left_sum+=t;
            }
            else right_sum+=t;
        }
        cout << left_sum*right_sum<<"\n";
    }
}