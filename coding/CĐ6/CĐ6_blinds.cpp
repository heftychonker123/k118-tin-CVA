#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define str string
void solve(vect<str> &v , ll rows , ll cols){
    vect<ll> freq(5,0);     
    for (int i = 1; i < rows; i += 5) {
        for (int j = 1; j < cols; j += 5) {
            int count = 0;
            for (int t = 0; t < 4; t++) {
                for (int m = 0; m < 4; m++) {
                    if (v[i + t][j + m] == '*') {
                        count++;
                    }
                }
            }
            freq[count/4]++;
        }
    }

    for (const ll &x : freq){
        cout << x << " ";
    }
    cout << "\n";
}

int main(){
    freopen("blinds.inp" , "r" , stdin);
    freopen("blinds.out" , "w" , stdin);
    int n,m; 
    cin >> n >> m;
    vect<str> apartment(5*n+1);
    for (int i=0 ; i<5*n+1 ; i++){
        cin >> apartment[i];
    }
    solve(apartment , 5*n+1 , 5*m+1);
    return 0;
}
