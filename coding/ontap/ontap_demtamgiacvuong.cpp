#include <bits/stdc++.h>
using namespace std;
#define filename "demtamgiacvuong"
#define ll long long
#define ld long double

pair<bool, ld> check(pair<ll,ll> A, pair<ll,ll> B, pair<ll,ll> C) {
    ll ax = A.first, ay = A.second;
    ll bx = B.first, by = B.second;
    ll cx = C.first, cy = C.second;
    
    ll dotA = (bx-ax)*(cx-ax) + (by-ay)*(cy-ay);
    ll dotB = (ax-bx)*(cx-bx) + (ay-by)*(cy-by);
    ll dotC = (ax-cx)*(bx-cx) + (ay-cy)*(by-cy);
    
    ld S = 0.5 * abs(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
    
    bool res = (dotA == 0 || dotB == 0 || dotC == 0);
    return {res, S};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<pair<ll,ll>> v(n);
    ll res = 0;
    ld area = 0;
    
    for (int i=0; i<n; i++) 
        cin >> v[i].first >> v[i].second;
    
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int l=j+1; l<n; l++){
                auto result = check(v[i], v[j], v[l]);
                if (result.first){
                    res++;
                    area = max(result.second, area);
                }
            }
        }
    }
    
    cout << res << "\n";
    if (res != 0) 
        cout << fixed << setprecision(3) << area;
}