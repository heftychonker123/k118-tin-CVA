#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

void solve(vect<vect<ll>> board, ll height , ll width){
    ll md_sum=0 , ad_sum=0 , nmdu_sum=0 , nmdl_sum=0 , nadu_sum=0 , nadl_sum=0 , fumd_sum=0 , fdad_sum=0;
    for (int i=0 ; i<height ; i++){
        md_sum += board[i][i];
    }
    for (int i=0 ; i<height ; i++){
        ad_sum += board[i][height-1-i];
    }
    for (int i=0 ; i<height-1 ; i++){
        nmdu_sum += board[i][i+1];
    }
    for (int i=1 ; i<height ; i++){
        nmdl_sum += board[i][i-1];
    }
    for (int i=height-1 ; i>=1 ; i--){
        nadl_sum += board[i][height-i];
    }
    for (int i=0 ; i<height-1 ; i++){
        nadu_sum += board[i][height-2-i];
    }
    for (int i=0 ; i<height ; i++){
        for (int j=i+1 ; j<height ; j++){
            fumd_sum += board[i][j];
        }
    }
    for (int i=0 ; i<height ; i++){
        for (int j=height-i ; j<height ; j++){
            fdad_sum += board[i][j];
        }
    }
    cout << md_sum << "\n";
    cout << ad_sum << "\n";
    cout << nmdu_sum + nmdl_sum << "\n";
    cout << nadu_sum+nadl_sum << "\n";
    cout << fumd_sum << "\n";
    cout << fdad_sum << "\n";
}
int main(){
    //freopen("matranvuong.cpp" , "r" , stdin);
    //freopen("matranvuong.cpp" , "w" , stdout);
    int n ; cin >> n;
    vect<vect<ll>> board(n , vect<ll>(n));
    for (int i=0 ; i<n ; i++){
        for (int j=0; j<n ; j++){
            cin >> board[i][i];
        }
    }
    solve(board,n,n);
}