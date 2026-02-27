#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

void solve(ll n){
    int temp=1;
    int upper=0 , lower=n-1 , left=0 , right=n-1;
    vect<vect<ll>> v(n , vect<ll>(n));
    while (left<=right && upper<=lower){
        //Fill from upper left to lower left
        for (int i=upper ; i<=lower ; i++){
            v[i][left]=temp;
            temp++;
        }
        left++;
        //Fill from lower left to lower right
        for (int i=left ; i<=right ; i++){
            v[lower][i]=temp;
            temp++;
        }
        lower--;
        //Fill from lower right to upper right
        for (int i=lower ; i>=upper ; i--){
            v[i][right]=temp;
            temp++;
        }
        right--;
        //Fill from upper right to upper left
        for (int i=right ; i>=left ; i--){
            v[upper][i]=temp;
            temp++;
        }
        upper++;
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
int main(){
    //freopen("matranxoay.inp" , "r" , stdin);
    //freopen("matranxoay.out" , "w" , stdout);
    int n; cin >> n;
    solve(n);
    return 0;
}