#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b){
    return a*b / gcd(a,b);
}

int main(){
    //freopen("ucbcd.inp","r",stdin);
    //freopen("ucbcd.out","w",stdout);
    int n; cin >> n;
    vector <int> v={};
    for (int i=0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    int ans1=gcd(v[0],v[1]);
    int ans2=lcm(v[0],v[1]);
    for (int i=2; i<v.size(); i++){
        ans1=gcd(ans1,v[i]);
    }
    for (int i=2; i<v.size();i++){
        ans2=lcm(ans2,v[i]);
    }
    cout << ans1 << endl;
    cout << ans2;
    return  0;
}