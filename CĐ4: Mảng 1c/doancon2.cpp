#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ; cin >> n;
    long long temp=1 , ans=0;
    long long curr;
    vector <long double> v(n);
    for (long long i=0 ; i<n ; i++){
        long long t; cin >> t;
        if (t>=0) v[i]=1;
        else v[i]=0;
    }
    curr=v[0];
    for (long long i=1 ; i < n ;i++){
        if (curr!=v[i]) {
            temp ++ ;
        }
        else{
            ans=max(ans,temp);
            temp=1;
        }
        curr=v[i];
    }
    ans=max(ans,temp);
    cout << ans;
}
