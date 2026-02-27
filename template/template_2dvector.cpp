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
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    // bảng ô vuông n x m;
    int n,m ; cin >> n >> m;
    vect<vect<ll>> v(n);
    for (int i=0 ; i<n ; i++){
        vect<ll> temp(m);
        for (int j=0 ; j<m ; j++) cin >> temp[j];
        v[i]=temp;
    }
    return 0;
}