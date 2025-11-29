#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
//class
//function
bool check(vector<ll> v , ll length){
    for (int i=0 ; i<length ; i++){
        if (v[i]!=v[length-i-1]) return false; 
    }
    return true;
}
//initialization code
int main(){
    int n; cin >> n;
    vector<ll> v={};
    for (int i=0; i<n ; i++){
        ll t; cin >> t;
        v.pb(t);
    }
    if (check(v,n)) cout << "YES";
    else cout << "NO";
    return 0;
}


