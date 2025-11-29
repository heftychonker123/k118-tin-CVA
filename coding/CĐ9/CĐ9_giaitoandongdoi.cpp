#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define llmax LLONG_MAX

void solve(vect<vect<ll>> &v , ll r , ll c){
    vect<ll> time(r,0);
    vect<ll> score(r,0);

    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (v[i][j]!=0){
                score[i]+=10;
            }
            time[i]+=v[i][j];
        }
    }

    int best_score = *max_element(score.begin(), score.end());
    ll best_time = llmax;
    int res = -1;

    for (int t=0; t<r; t++){
        if (score[t] == best_score){
            if (time[t] < best_time){
                best_time = time[t];
                res = t;
            }
        }
    }

    cout << (res+1) << "\n"; // +1 for 1-based team index
}

int main(){
    int n,m; 
    cin >> n >> m;
    vect<vect<ll>> v(n , vect<ll>(m));
    for (int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> v[i][j];
        }
    }
    solve(v,n,m);
    return 0;
}
