#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    freopen("CAU3.INP" , "r" , stdin);
    freopen("CAU3.OUT" , "w" , stdout);
    int n; cin >> n;
    vector <long long> v(n);
    for (int i=0; i <n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int temp=1;
    for (const long long i:v){
        if (i==temp) temp++;
    }
    cout << temp;
}