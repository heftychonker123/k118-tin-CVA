#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN;
#define llmax LLONG_MAX;
#define pb push_back;
//class
//function
//initialization code
int main(){
    int t; cin >> t;
    for (int test_case=0 ; test_case<t ; test_case++){
        int n; cin >> n;
        vector<ll> v(n);
        ll ans=0;
        for (int i=0 ; i<n ; i++) cin >> v[i];
        for (int i=0; i<n ; i++){
            ll curr_sum=0;
            for (int j=i ; j<n ; j++){
                curr_sum+=v[j];
                if (curr_sum%2==0) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}