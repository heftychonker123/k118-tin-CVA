#include <bits/stdc++.h>
using namespace std;
#define filename "insort"
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

void solve(vect<ll> v , ll length){
    for (int t = 1; t < length; t++) {
        ll temp = v[t];
        int prev = t - 1;
        while (prev >= 0 && v[prev] > temp) {
            v[prev + 1] = v[prev];
            prev--;
        }
        v[prev + 1] = temp;
        cout << "Buoc " << t << ": ";
        for (int j = 0; j < length; j++) {
            cout << v[j];
            if (j < length - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll n; cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    solve(v, n);
    return 0;
}