#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

bool check_solid(const vect<vect<ll>> &board , ll minr , ll maxr , ll minc , ll maxc){
    for (int i=minr ; i<=maxr ; i++){
        for (int j=minc ; j<=maxc ; j++){
            if (board[i][j]==0) return false;
        }
    }
    return true;
}

bool check_hollow(const vect<vect<ll>> &board , ll minr , ll maxr , ll minc , ll maxc){
    for (int j=minc ; j<=maxc ; j++){
        if (board[minr][j]==0 || board[maxr][j]==0) return false;
    }
    for (int i=minr ; i<=maxr ; i++){
        if (board[i][minc]==0 || board[i][maxc]==0) return false;
    }
    return true;
}

bool check_hole(const vect<vect<ll>> &board , ll minr , ll maxr , ll minc , ll maxc){
    int irmin=-1, irmax=-1, icmin=-1, icmax=-1;
    for (int i=minr+1; i<maxr; i++){
        for (int j=minc+1; j<maxc; j++){
            if (board[i][j]==0){
                if (irmin==-1){
                    irmin=irmax=i;
                    icmin=icmax=j;
                } else {
                    irmin=min(irmin,i);
                    irmax=max(irmax,i);
                    icmin=min(icmin,j);
                    icmax=max(icmax,j);
                }
            }
        }
    }
    if (irmin==-1) return false;
    for (int i=irmin; i<=irmax; i++){
        for (int j=icmin; j<=icmax; j++){
            if (board[i][j]!=0) return false;
        }
    }
    for (int i=minr+1; i<maxr; i++){
        for (int j=minc+1; j<maxc; j++){
            if (i<irmin || i>irmax || j<icmin || j>icmax){
                if (board[i][j]==0) return false;
            }
        }
    }
    return true;
}

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
    int res1 = 0 , res2 = 0 , res3 = 0;
    vect<vect<bool>> visited(length, vect<bool>(width,false));

    for (int i = 0 ; i < length ; i++){
        for (int j = 0 ; j < width ; j++){
            if (board[i][j] == 1 && !visited[i][j]){
                stack<pair<ll , ll>> st;
                st.push({i,j});
                ll minrow=i, maxrow=i, mincol=j, maxcol=j;

                while (!st.empty()){
                    auto [cx, cy] = st.top();
                    st.pop();
                    if (visited[cx][cy]) continue;
                    visited[cx][cy] = true;

                    minrow = min(minrow, cx);
                    maxrow = max(maxrow, cx);
                    mincol = min(mincol, cy);
                    maxcol = max(maxcol, cy);

                    vect<pair<ll,ll>> n = neighbor(length,width,cx,cy);
                    for (const auto &p : n){
                        if (board[p.first][p.second] == 1 && !visited[p.first][p.second]){
                            st.push(p);
                        }
                    }
                }
                if (check_solid(board , minrow , maxrow , mincol , maxcol)){
                    res1++;
                    res3++;
                }
                else if (check_hollow(board , minrow , maxrow , mincol , maxcol)){
                    res3++;
                    if (check_hole(board , minrow , maxrow , mincol , maxcol)){
                        res2++;
                    }
                }
            }
        }
    }
    cout << res3 << "\n";
    cout << res1 << "\n";
    cout << res2 << "\n";
}

int main(){
    int m,n; 
    cin >> m >> n;
    vect<vect<ll>> v(m, vect<ll>(n));
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> v[i][j];
        }
    }
    dfs(v,m,n);
    return 0;
}
