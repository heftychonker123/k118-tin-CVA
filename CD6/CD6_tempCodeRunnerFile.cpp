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
vect<vect<ll>> solve(ll n) {
    ll row_up = 0, col_left = 0, row_down = n - 1, col_right = n - 1;
    vect<vect<ll>> v(n, vect<ll>(n));
    ll temp = 1;

    while (row_up <= row_down && col_left <= col_right) {
        // Left to right
        for (int i = col_left; i <= col_right; i++) {
            v[row_up][i] = temp++;
        }
        row_up++;

        // Top to bottom
        for (int i = row_up; i <= row_down; i++) {
            v[i][col_right] = temp++;
        }
        col_right--;

        // Right to left
        if (row_up <= row_down) {
            for (int i = col_right; i >= col_left; i--) {
                v[row_down][i] = temp++;
            }
            row_down--;
        }

        // Bottom to top
        if (col_left <= col_right) {
            for (int i = row_down; i >= row_up; i--) {
                v[i][col_left] = temp++;
            }
            col_left++;
        }
    }

    return v;
}




int main(){
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    int n; cin>>n;
    vect<vect<ll>> ans=solve(n);
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}