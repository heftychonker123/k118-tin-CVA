#include <bits/stdc++.h>
using namespace std;
#define filename "taoso"
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

void solve(){
}

int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    vect<ll> prime_fact;
    if (n%2==0){
        while (n%2==0){
            prime_fact.pb(2);
            n/=2;
        }
    }
    for (int i=3 ; i*i<n ; i+=2){
        if (n%i==0){
            while (n%i==0){
                prime_fact.pb(i);
                n/=i;
            }
        }
    }
    if (n>1) prime_fact.pb(n);
    vect<str> v;
    for (const ll &i : prime_fact){
        v.pb(to_string(i));
    }
    sort(v.begin(), v.end(), [](const str &a, const str &b) {
    return a + b > b + a;
    });

    for (const str &i : v) cout << i;
    return 0;
}