#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int cnt[MAXN];   
int prefix[MAXN]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("SOUOC.INP" , "r" , stdin);
    //freopen("SOUOC.OUT" , "w" , stdout);
    
    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i)cnt[j]+=i;
    
    int K, Q;
    cin >> K >> Q;
    
    
    for (int i = 1; i < MAXN; i++)
        prefix[i] = prefix[i-1] + (cnt[i] >= K ? 1 : 0);
    
    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << prefix[R] - prefix[L-1] << "\n";
    }
    
    return 0;
}