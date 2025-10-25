#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    str a,b ; cin >> a >> b;
    int n; cin >> n;
    if (n==1) cout << a;
    if (n==2) cout << a << b;
    else{
        vector<string> v={a,b};
        for (int i=2 ; i<n ; i++){
            v.pb(v[i-1] + v[i-2]);
        }
        cout << v[n-1];
    }
    return 0;
}