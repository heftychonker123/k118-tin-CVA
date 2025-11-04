#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
    int n; cin >> n;
    map<long long , long long> freq;
    for (int i=0 ; i<n ; i++){
        long long t; cin >> t;
        freq[t]++;
    }
    for (auto & [num,frequency]:freq){
        cout << num << ":" << frequency << "\n";
    }
}