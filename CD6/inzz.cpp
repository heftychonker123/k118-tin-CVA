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
    int n,m ; cin >> n ; m=n;
    vect<vect<ll>> v(n);
    for (int i=0 ; i<n ; i++){
        vect<ll> temp(m);
        for (int i=0 ; i<m ; i++) cin >> temp[i];
        v[i]=temp;
    }
    for (int i=0 ; i<n ; i++){
        if (i%2!=0){
            for (int j=n-1 ; j>-1 ; j--){
                cout << v[i][j] << " ";
            }
        }
        else for (int j=0 ; j<n ; j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
