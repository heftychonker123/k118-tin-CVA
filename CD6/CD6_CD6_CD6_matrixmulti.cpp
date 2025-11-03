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
    int n,m,p ; cin >> n >> m >> p;
    vect<vect<ll>> a(n);
    for (int i=0 ; i<n ; i++){
        vect<ll> temp(m);
        for (int i=0 ; i<m ; i++) cin >> temp[i];
        a[i]=temp;
    }
    vect<vect<ll>> b(m);
    for (int i=0 ; i<m ; i++){
        vect<ll> temp(p);
        for (int i=0 ; i<p ; i++) cin >> temp[i];
        b[i]=temp;
    }
    vect<vect<ll>> c(n , vect<ll>(p));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<p ; j++){
            ll sum=0;
            for (int k=0 ; k<m ;k++){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<p ; j++){
            cout << c[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}