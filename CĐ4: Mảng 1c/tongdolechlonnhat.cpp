#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
//class
//function
//initialization code
int main(){
    int t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        //put your main init code here
        int n; cin >> n;
        vector <ll> ans={};
        vector <ll> v(n);
        ll o=0;
        for (int i=0 ; i<n ; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i=0 ; i<n ; i++){
            if (2*i==n) ans.pb(v[i]);
            else{
                ans.pb(v[i]);
                ans.pb(v[n-i-1]);
            }
        }
        for (int i=0 ; i<n ; i++){
            o+=abs(ans[i%n]-ans[(i+1)%n]);
        }
        cout << o << endl;
    }
    return 0;
}