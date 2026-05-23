
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vect vector
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,n ; cin >> x >> n;
    set<ll> pos;
    multiset<ll> segments;
    segments.insert(x); pos.insert(0) ; pos.insert(x);
    for (int i = 0 ; i<n ; i++){
        ll t ; cin >> t;
        auto pit = pos.upper_bound(t);
        auto pit2 = pit; pit2--;
        ll length = *pit - *pit2;
        auto it = segments.find(length);
        if (it != segments.end()) segments.erase(it);
        segments.insert(t - *pit2) , segments.insert(*pit - t);
        cout << *segments.rbegin() << " ";
        pos.insert(t);
    }
}