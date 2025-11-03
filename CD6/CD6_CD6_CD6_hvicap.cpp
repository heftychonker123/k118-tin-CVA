#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define vect vector
//class
//function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n ; m=n;

    vect<vect<ll>> v(n);
    for (int i = 0; i < n; i++){
        vect<ll> temp(m);
        for (int j = 0; j < m; j++) cin >> temp[j];
        v[i] = temp;
    }

    vector<ll> order(m);
    for (int i = 0; i < m; i++) order[i] = i;

    int u, t;
    cin >> u >> t;
    swap(order[u - 1], order[t - 1]);
    for (const vect<ll>& temp : v){
        for (const ll& i : order){
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
