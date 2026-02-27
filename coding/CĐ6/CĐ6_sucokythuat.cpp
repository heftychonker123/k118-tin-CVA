#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define pb push_back
int main(){
    int m,n; 
    cin >> m >> n;
    vect<vect<ll>> refri(m, vect<ll>(n));
    vect<vect<ll>> time(m, vect<ll>(n,0));

    // Nhập dữ liệu
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> refri[i][j];
        }
    }

    // 4 hướng cơ bản
    vect<vect<int>> dirs = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            int count=0;
            for (auto &dir : dirs){
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni>=0 && nj>=0 && ni<m && nj<n){
                    if (refri[ni][nj]==0) count++;
                }
            }

            if (count > 1){
                time[i][j] = 1;
            } else {
                vect<ll> max_time;
                for (auto &dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni>=0 && nj>=0 && ni<m && nj<n){
                        max_time.pb(time[ni][nj]);
                    }
                }
                if (!max_time.empty()){
                    time[i][j] = *max_element(max_time.begin(), max_time.end());
                } else {
                    time[i][j] = 0;
                }
            }
        }
    }

    ll res=0;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            res = max(res,time[i][j]);
        }
    }

    // In ma trận time
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cout << time[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << res;
}
