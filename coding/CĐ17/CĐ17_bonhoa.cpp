#include <bits/stdc++.h>
using namespace std;
#define filename "bonhoa"
#define ll long long
#define llmin LLONG_MIN
#define vect vector
ll board[100][100] = {};
bool visited[100][100] = {};
void dfs(pair<ll,ll> root , ll m , ll n , ll &cir , ll &area){
    auto [x,y] = root;
    if (visited[x][y]) return;
    visited[x][y]=true;
    area++;
    ll cnt = 0;
    for (const auto [dirx , diry] : vect<pair<ll,ll>>{{-1,0} , {1,0} , {0,-1} , {0,1}}){
        if (x+dirx<0||x+dirx>=m||y+diry<0||y+diry>=n) continue;
        else if (board[x+dirx][y+diry] == 1) cnt++;
    }

    cir+=(4-cnt);
    
    for (const auto [dirx , diry] : vect<pair<ll,ll>>{{-1,0} , {1,0} , {0,-1} , {0,1}}){
        if (x+dirx<0||x+dirx>=m||y+diry<0||y+diry>=n) continue;
        else{
            if (board[x+dirx][y+diry] == 1){
                dfs({x+dirx , y+diry} , m , n , cir , area);
            }
        }
    }
}

void solve(){
    ll m,n ; cin >> m >> n;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++) cin >> board[i][j];
    }
    ll islands=0;
    ll maxCir=llmin , maxArea=llmin;
    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (!visited[i][j] && board[i][j]==1){
                islands++;
                ll cir=0,area=0;
                dfs({i,j} , m , n , cir, area);
                maxCir = max(cir,maxCir);
                maxArea = max(area , maxArea);
            }
        }
    }
    cout << maxArea << " " << maxCir;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}