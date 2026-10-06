#include <bits/stdc++.h>
using namespace std;
#define ll long long

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MAXN = 2e5 , MAXV = 1e5;
int n , a[MAXN + 1];
ll randVal[MAXV + 1];

void assignVal(){
    for (int i = 1 ; i<=MAXV ; i++) randVal[i] = abs(int(rng()));
}

ll prefXor[MAXN + 1];
ll permuteHash[MAXV + 1];

// Kiểm tra xem một đoạn con có phải là hoán vị ko
void solve(){
    for (int i = 1 ; i <= MAXV ; i++){
        permuteHash[i] = permuteHash[i-1] ^ randVal[i];
    }
    for (int i = 1 ; i<=n ; i++){
        prefXor[i] = prefXor[i-1] ^ randVal[a[i]];
    }

    int queries ; cin >> queries;
    while (queries--){
        int l , r ; cin >> l >> r;
        int subXor = prefXor[r] ^ prefXor[l-1];
        if (subXor == permuteHash[r-l+1]) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}