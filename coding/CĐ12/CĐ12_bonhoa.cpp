#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
#define pb push_back
vect<pair<ll,ll>> neighbor(ll length , ll width , ll x_pos , ll y_pos){
    vect<pair<ll,ll>> dirs = {{0,1} , {0,-1} , {1,0} , {-1,0}};
    vect<pair<ll,ll>> res;
    for (const auto &dir : dirs){
        ll x_neighbor = x_pos + dir.first;
        ll y_neighbor = y_pos + dir.second;
        if (x_neighbor < length && y_neighbor < width && x_neighbor >= 0 && y_neighbor >= 0){
            res.push_back({x_neighbor,y_neighbor});
        }
    }
    return res;
}

void dfs(vect<vect<ll>> &board , ll length , ll width){
    ll res = 0;
    vect<vect<bool>> visited(length, vect<bool>(width,false));
    vect<ll> area;
    vect<ll> cir;
    for (int i = 0 ; i < length ; i++){
        for (int j = 0 ; j < width ; j++){
            if (board[i][j] == 1 && !visited[i][j]){
                stack<pair<ll , ll>> st;
                st.push({i,j});
                ll pot_area = 0;
                ll pot_cir = 0;
                res++;
                while (!st.empty()){
                    auto [cx, cy] = st.top();
                    st.pop();
                    if (visited[cx][cy]) continue;
                    visited[cx][cy] = true;

                    pot_area++;
                    ll temp = 0;

                    vect<pair<ll,ll>> n = neighbor(length,width,cx,cy);
                    for (const auto &p : n){
                        if (board[p.first][p.second] == 1){
                            temp++;
                            if (!visited[p.first][p.second]){
                                st.push(p);
                            }
                        }
                    }
                    pot_cir += (4 - temp);
                }

                area.pb(pot_area);
                cir.pb(pot_cir);
            }
        }
    }

    cout << *max_element(area.begin() , area.end())<< " " << *max_element(cir.begin() , cir.end())<< "\n";
}

int main(){
    int m,n ; cin >> m >> n;
    vect<vect<ll>> v(m, vect<ll>(n));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
        }
    }
    dfs(v,m,n);
    return 0;
}
