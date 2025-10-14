#include <bits/stdc++.h>
using namespace std;

long long calc(string n){
    long long ans=0;
    for (char i:n){
        int t= i-'0';
        ans+=t;
    }
    return ans;
}


int main(){
    string a,b; cin >> a >> b;
    long long suma=calc(a);
    long long sumb=calc(b);
    cout << suma*sumb;
}