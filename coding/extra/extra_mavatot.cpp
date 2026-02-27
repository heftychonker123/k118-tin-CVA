#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> knightMoves = {
    {-2,-1},{-2,1},{2,-1},{2,1},
    {-1,-2},{-1,2},{1,-2},{1,2}
};

struct State {
    int dx, dy;
    int turn;
    int steps;
};

void solve(int hx,int hy,int px,int py){
    queue<State> q;
    set<tuple<int,int,int>> visited;

    // mặc định knight đi trước
    q.push({hx-px, hy-py, 0, 0});
    visited.insert({hx-px, hy-py, 0});

    while(!q.empty()){
        auto [dx,dy,turn,steps] = q.front(); q.pop();

        if(turn==0){ // knight move
            for(auto [kx,ky]:knightMoves){
                int ndx=dx+kx, ndy=dy+ky;
                if(ndx==0 && ndy==0){
                    cout<<"YES\n"<<steps+1<<"\n";
                    return;
                }
                if(!visited.count({ndx,ndy,1})){
                    visited.insert({ndx,ndy,1});
                    q.push({ndx,ndy,1,steps+1});
                }
            }
        } else { // pawn move
            int ndx=dx-1, ndy=dy;
            if(ndx==0 && ndy==0){
                cout<<"NO\n";
                return;
            }
            if(!visited.count({ndx,ndy,0})){
                visited.insert({ndx,ndy,0});
                q.push({ndx,ndy,0,steps});
            }
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int hx,hy,px,py; 
    cin>>hx>>hy>>px>>py;
    solve(hx,hy,px,py);
}
