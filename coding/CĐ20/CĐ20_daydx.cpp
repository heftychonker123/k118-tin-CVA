#include <bits/stdc++.h>
using namespace std;
#define filename "Daydx"
#define ll long long
#define pb push_back
#define vect vector

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

struct Tracer{
    ll x,y,z;
    Tracer(ll x, ll y , ll z) : x(x) , y(y) , z(z) {};
};
string reconstruct(ll m, ll n, vect<vect<Tracer>> &trace) {
    if (m > n) return "";
    if (m == n) {
        if (trace[m][n].z != -1) return to_string(trace[m][n].z);
        return "";
    }
    Tracer t = trace[m][n];
    if (t.z != -1) {
        string inner = reconstruct(t.x, t.y, trace);
        return to_string(t.z) + inner + to_string(t.z);
    } else {
        return reconstruct(t.x, t.y, trace);
    }
}

ll dp(ll m , ll n , vect<ll> &v , vect<vect<ll>> &memo , vect<vect<Tracer>> &trace){
    if (m>n) return 0;
    if (m == n) {
        trace[m][n] = Tracer(-1, -1, v[m-1]);
        return memo[m][n] = 1;
    }
    if (memo[m][n]!=-1) return memo[m][n];
    ll include = LLONG_MIN , left = LLONG_MIN , right = LLONG_MIN;
    if (v[m-1] == v[n-1]) include = dp(m+1 , n-1 , v , memo , trace) + 2;
    left = dp(m+1 , n , v , memo , trace);
    right = dp(m , n-1 , v , memo , trace);
    if (include >= left && include >= right){
        trace[m][n] = Tracer(m+1 , n-1 , v[m-1]);
        return memo[m][n] = include;
    }
    else if (left > right){
        trace[m][n] = Tracer(m+1 , n , -1);
        return memo[m][n] = left;
    }
    else if (right > left){
        trace[m][n] = Tracer(m , n-1 , -1);
        return memo[m][n] = right;
    }
    else{
        if (v[m] > v[m-1] && v[n-1] > v[n])trace[m][n] = Tracer(m+1 , n , -1);
        else trace[m][n] = Tracer(m , n-1 , -1);
        return memo[m][n] = right;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    ll n ; cin >> n;
    vect<ll> v(n); for (int i=0 ; i<n ; i++) cin >> v[i];
    vect<vect<Tracer>> trace(n+1 , vect<Tracer>(n+1 , Tracer(-1,-1,-1)));
    vect<vect<ll>> memo(n+1 , vect<ll> (n+1 , -1));
    cout << dp(1 , n , v , memo , trace) << "\n";
    string res = reconstruct(1,n,trace);
    for (int i=0 ; i<res.size()-1 ; i++){
        cout << res[i] << " ";
    }
    cout << res[res.size()-1];
    return 0;
}