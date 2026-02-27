#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
ll n,k;
vect<ll> v;
void solve(){
    cin >> n >> k;
    v.resize(k);
    for (int i=0 ; i<k ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll cnt = 0;
    while (true){
        cnt++;
        ll i = k-1;
        // Tìm phần tử chưa đạt tới giá trị lớn nhất có thể
        while (i>-1 && v[i] == n - k + i + 1) i--; 
        if (i==-1) break; // Cấu hình cuối cùng
        v[i]++ ; 
        for (int j = i+1 ; j<k ; j++){
            v[j] = v[j-1] + 1;
        }
    }
    cout << cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}