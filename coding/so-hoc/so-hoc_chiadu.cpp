#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

ll solve(ll a, ll b, ll t) {
    if (b==1){
        return a%t;
    }
    ll h = solve(a,b/2,t);
    h = (h*h)%t;
    if (b%2==1){
        h = (h*a)%t;
    }
    return h;
}

int main(){
    ll a,b,t ; cin >> a >> b >> t;
    ll m = solve(a,b,t);
    cout << m;
    return 0;
}