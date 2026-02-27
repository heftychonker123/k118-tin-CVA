#include <bits/stdc++.h>
using namespace std;
#define filename "xaufibo"
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
ll fibo[46];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Precalculate Fibbonacci sequence
    fibo[0] = 1 ; fibo[1] = 1;
    for (int i=2 ; i<46 ; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }


    ll t ; cin >> t;
    while (t--){
        ll n,k ; cin >> n >> k;
        if (k==0){
            cout << '0' << '\n';
            continue;
        }
        else if (n==0){
            cout << '1' << "\n";
            continue;
        }
        else if (n==1){
            cout << '0' << '\n';
            continue;
        }
        vector<ll> prev2(k+1, 0), prev1(k+1, 0), curr(k+1, 0);

        // base cases
        for (int j = 0; j <= k; j++) {
            prev2[j] = 1;
            prev1[j] = 0;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j >= fibo[i-2]) {
                    ll left = (fibo[i-2] <= k ? prev2[fibo[i-2]] : 0);
                    ll right = prev1[j - fibo[i-2]];
                    curr[j] = left + right;
                } else {
                    curr[j] = prev2[j];
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        cout << prev1[k] << "\n";

    }
    return 0;
}