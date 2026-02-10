#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vect vector

bool obs[8][8];
void allLeft(vect<vect<bool>> &visited , ll x , ll y , ll dx=1 , ll dy=0 , ll step = 0){
    if (visited[x][y]){
        cout << step-1;
        return;
    }
    visited[x][y] = true;
    ll nx = x+dx , ny = y+dy;
    while (nx<0 || nx>=8 || ny<0 || ny>=8 || obs[nx][ny]){
        ll t = dx;
        dx = -dy; 
        dy = t; 
        nx = x+dx; 
        ny = y+dy;
    }
    allLeft(visited,nx,ny,dx,dy,step+1);
}

ll best(vect<vect<bool>> &visited , ll x , ll y , ll dx=1 , ll dy=0 , ll step = 0){
    if (visited[x][y]) return (step-1);
    visited[x][y] = true;

    ll lx = dx , ly = dy , rx = dx , ry = dy;

    while (x+lx<0 || x+lx>=8 || y+ly<0 || y+ly>=8 || obs[x+lx][y+ly]){
        ll t = lx;
        lx = -ly;
        ly = t;
    }
    ll left = best(visited,x+lx,y+ly,lx,ly,step+1);

    while (x+rx<0 || x+rx>=8 || y+ry<0 || y+ry>=8 || obs[x+rx][y+ry]){
        ll t = rx;
        rx = ry;
        ry = -t;
    }
    ll right = best(visited,x+rx,y+ry,rx,ry,step+1);

    return max(left,right);
}

void solve(){
    ll n; 
    cin >> n;
    while (n--){
        string s ; cin >> s;
        obs[s[1] - '1'][s[0]-'A'] = true;
    }
    vect<vect<bool>> visited(8 , vect<bool>(8,false));
    allLeft(visited,0,0);
    cout << "\n";

    visited.assign(8, vect<bool>(8,false));
    cout << best(visited,0,0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("conran.inp" , "r" , stdin);
    //freopen("conran.out" , "w" , stdout);
    solve();
    return 0;
}
