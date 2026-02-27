#include <bits/stdc++.h>
using namespace std;
#define filename "catco"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map

vect<pair<ll,ll>> neighbor(vect<vect<ll>> &board , ll length , ll width , ll x_pos , ll y_pos){
    vect<pair<ll,ll>> dirs = {{0,1} , {0,-1} , {1,0} , {-1,0}};
    vect<pair<ll,ll>> res;
    for (const auto &dir : dirs){
        ll nx = x_pos + dir.first;
        ll ny = y_pos + dir.second;
        bool add = true;
        if (nx >= 1 && nx < length-1 && ny >= 1 && ny < width-1){
            for (int i = nx-1 ; i <= nx+1 ; i++){
                for (int j = ny-1 ; j <= ny+1  ; j++){
                    if (board[i][j] == -1){ // blocked cell
                        add = false;
                    }
                }
            }
        }
        if (add) res.push_back({nx,ny}); 
    }
    return res;
}

void dfs(vect<vect<ll>> &board , ll length , ll width , pair<ll,ll> root){
    ll res = 0;
    vect<vect<bool>> visited(length, vect<bool>(width,false));
    vect<vect<bool>> occupied(length, vect<bool>(width,false));
    stack<pair<ll,ll>> st;
    st.push(root);
    visited[root.first][root.second] = true;

    while (!st.empty()){
        pair<ll,ll> curr = st.top(); st.pop();
        ll cx = curr.first;
        ll cy = curr.second;

        vect<pair<ll,ll>> n = neighbor(board,length,width,cx,cy);

        for (const pair<ll,ll> neighbor : n){
            ll nx = neighbor.first;
            ll ny = neighbor.second;
            if (!visited[nx][ny]){
                st.push({nx,ny});
                visited[nx][ny]=true;
                for (int i = nx-1 ; i <= nx+1 ; i++){
                    for (int j = ny-1 ; j <= ny+1  ; j++){
                        occupied[i][j] = true;  // FIXED
                    }
                }
            }
        }
    }
    for (int i=0 ; i<length ; i++){
        for (int j=0 ; j<width ; j++){   // FIXED
            if (occupied[i][j]) res++;
        }
    }
    cout << res << "\n";
}

int main(){
    freopen(filename".inp" , "r" , stdin);
    ll h,w ; cin >> h >> w;
    vect<vect<ll>> board;
    pair<ll,ll> root;
    for (int i=0 ; i<h ; i++){
        vect<ll> temp;
        for (int j=0 ; j<w ; j++){
            char t; cin >> t;
            if (t=='M') {
                temp.pb(0);
                root = {i,j};
            }
            else if (t=='+') temp.pb(-1);
            else temp.pb(0);
        }
        board.pb(temp);   // FIXED
    }
    dfs(board,h,w,root);
    return 0;
}