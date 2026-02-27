#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vect vector

// Check if v[row][col] satisfies the comment conditions
bool check(const vect<vect<ll>> &v , ll rows , ll cols , ll row , ll col){
    // check column: v[row][col] should be >= all in its row
    for (int j=0 ; j<cols ; j++){
        if (v[row][col] < v[row][j]) return false;
    }
    // check row: v[row][col] should be <= all in its col
    for (int i=0 ; i<rows ; i++){
        if (v[row][col] > v[i][col]) return false;
    }
    return true;
}

void solve(const vect<vect<ll>> &v , ll rows , ll cols){
    vect<pair<int,int>> ans;
    for (int i=0 ; i<rows ; i++){
        for (int j=0 ; j<cols ; j++){
            if (check(v,rows,cols,i,j)){
                ans.pb({i,j});
            }
        }
    }
    if (ans.empty()){
        cout << "0\n";
    } 
    else {
        for (auto &p : ans){
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
    }
}

int main(){
    freopen("yenngua.inp" , "r" , stdin);
    freopen("yenngua.out" , "w" , stdout);
    int n,m; cin >> n >> m;
    vect<vect<ll>> v(n, vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++) cin >> v[i][j];
    }

    solve(v,n,m);
    return 0;
}
