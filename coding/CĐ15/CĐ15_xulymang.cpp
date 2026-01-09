#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;

    vect<ll> A(N+1);
    for (int i=1; i<=N; i++) cin >> A[i];

    vect<ll> L(M+1), R(M+1), D(M+1);
    for (int i=1; i<=M; i++){
        cin >> L[i] >> R[i] >> D[i];
    }

    vect<ll> use(M+2,0);
    for (int i=0; i<K; i++){
        int x,y; cin >> x >> y;
        use[x] += 1;
        use[y+1] -= 1;
    }
    for (int i=1; i<=M; i++) use[i] += use[i-1];

    vect<ll> diff(N+2,0);
    for (int i=1; i<=M; i++){
        if (use[i] > 0){
            diff[L[i]] += D[i] * use[i];
            diff[R[i]+1] -= D[i] * use[i];
        }
    }

    vect<ll> res(N+1,0);
    res[0] = 0;
    for (int i=1; i<=N; i++){
        res[i] = res[i-1] + diff[i];
    }

    for (int i=1; i<=N; i++){
        cout << A[i] + res[i] << " ";
    }
    cout << "\n";

    return 0;
}
