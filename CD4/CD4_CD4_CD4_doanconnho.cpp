#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
//function
ll max(vector<ll> v){
    ll ans=llmax;
    for (const ll i:v){
        ans=min(i,ans);
    }
    return ans;
}
vector <ll> solve(vector<ll> v, ll length , ll k){
    vector <ll> ans={};
    for (int i=0; i<length-k+1 ; i++){
        vector <ll> temp={};
        for (int j=0; j<k; j++){
            temp.pb(v[i+j]);
        }
        ans.pb(*min_element(temp.begin(),temp.end()));
    }
    return ans;
}
//initialization code
int main(){
    int n,k; cin >> n >> k;
    vector <ll> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    vector <ll> ans=solve(v,n,k);
    for (const ll i:ans){
        cout << i << "\n";
    }
    return 0;
}