#include <bits/stdc++.h>
using namespace std;
#define llmin LLONG_MIN;
#define llmax LLONG_MAX;
#define pb push_back;

int main(){
    int n; cin >> n;
    long long n_min=llmax;
    vector<long long> v(n);
    for (int i=0 ; i<n ; i++) {
        cin >> v[i];
        n_min=min(n_min , v[i]);
    }
    long long ans=0;
    for (const long long i:v){
        if (i==n_min) ans++;
    }
    cout << ans;
}