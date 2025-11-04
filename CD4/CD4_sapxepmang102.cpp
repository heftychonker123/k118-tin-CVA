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
    for (int tc=0 ; tc<t ; tc++){
        //put your main init code here here
        int n; cin >> n;
        vector <ll> v(n);
        for (int i=0 ; i<n ; i++) cin >> v[i];
        sort(v.begin() , v.end());
        for (const ll i:v) cout << i << " ";
        cout << endl;
    }
    return 0;
}