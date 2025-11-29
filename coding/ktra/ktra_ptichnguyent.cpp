#include <bits/stdc++.h>
using namespace std;

void solve(long long n){
    vector<long long> v;
    long long temp=2;
    long long ans=0;
    while (n>1){
        if (n%temp==0){
            v.push_back(temp);
            n/=temp;
            ans+=temp;
        }
        else temp++;
    }
    for (auto i=v.begin() ; i!=v.end()-1 ; i++){
        cout << *i << "*";
    }
    cout << v[v.size()-1] << "\n";
    cout << ans << "\n";
}
int main(){
    freopen("PHANTICHNT.INP" , "r" , stdin);
    freopen("PHANTICHNT.OUT" , "w" , stdout);
    int n ; cin >> n;
    solve(n);
    return 0;
}