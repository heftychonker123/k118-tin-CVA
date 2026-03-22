#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> inSubs;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;

        ll left = 0 , right = inSubs.size();
        while (left < right){
            ll mid = left + (right-left)/2;
            if (inSubs[mid] > t){
                left = mid+1;
            }
            else right = mid;
        }
        if (left < inSubs.size()) inSubs[left] = t;
        else inSubs.push_back(t);
    }
    cout << inSubs.size() << "\n";
    return 0;
}
