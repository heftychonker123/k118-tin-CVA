#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

vect<pair<ll,ll>> neighbor(ll length, ll width, ll x_pos, ll y_pos){
    vect<pair<ll,ll>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vect<pair<ll,ll>> res;
    for (const auto &dir : dirs){
        ll x_neighbor = x_pos + dir.first;
        ll y_neighbor = y_pos + dir.second;
        if (x_neighbor < length && y_neighbor < width && 
            x_neighbor >= 0 && y_neighbor >= 0){
            res.push_back({x_neighbor, y_neighbor});
        }
    }
    return res;
}

void countRectangles(vect<vect<ll>> &board, ll rows, ll cols){
    ll squares = 0, rectangles = 0;
    vect<vect<bool>> visited(rows, vect<bool>(cols, false));
    
    for (ll i = 0; i < rows; i++){
        for (ll j = 0; j < cols; j++){
            if (board[i][j] == 1 && !visited[i][j]){
                stack<pair<ll, ll>> st;
                st.push({i, j});
                ll area = 0;
                ll minRow = i, maxRow = i, minCol = j, maxCol = j;
                
                while (!st.empty()){
                    auto [cx, cy] = st.top();
                    st.pop();
                    
                    if (visited[cx][cy]) continue;
                    visited[cx][cy] = true;
                    area++;
                    
                    minRow = min(minRow, cx);
                    maxRow = max(maxRow, cx);
                    minCol = min(minCol, cy);
                    maxCol = max(maxCol, cy);
                    
                    vect<pair<ll,ll>> neighbors = neighbor(rows, cols, cx, cy);
                    for (const auto &[nx, ny] : neighbors){
                        if (board[nx][ny] == 1 && !visited[nx][ny]){
                            st.push({nx, ny});
                        }
                    }
                }
                
                ll height = maxRow - minRow + 1;
                ll width = maxCol - minCol + 1;
                ll expectedArea = height * width;
                
                if (area == expectedArea){
                    if (height == width){
                        squares++;
                    } else {
                        rectangles++;
                    }
                }
            }
        }
    }
    
    cout << squares << " " << rectangles << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll m, n; 
    cin >> m >> n;
    vect<vect<ll>> board(m, vect<ll>(n));
    
    for (ll i = 0; i < m; i++){
        for (ll j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    countRectangles(board, m, n);
    
    return 0;
}