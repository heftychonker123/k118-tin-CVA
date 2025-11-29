#include <bits/stdc++.h>
using namespace std;
#define filename "demdao"
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

vect<pair<ll,ll>> neighbor(vect<vect<ll>> board , ll length , ll width , ll x_pos , ll y_pos){ vect<pair<ll,ll>> dirs = {{0,1} , {0,-1} , {1,0} , {-1,0}}; vect<pair<ll,ll>> res; for (const auto &dir : dirs){ ll x_neighbor = x_pos + dir.first; ll y_neighbor = y_pos + dir.second; if (x_neighbor<length && y_neighbor<width && x_neighbor>=0 && y_neighbor>=0){ res.pb({x_neighbor,y_neighbor}); } } return res; }
void dfs(vect<vect<ll>> &board , ll length , ll width){
    ll res = 0;
    stack<pair<ll , ll>> st;
    set<pair<ll , ll>> visited;

    for (int i = 0 ; i < length ; i++){
        for (int j = 0 ; j < width ; j++){
            if (board[i][j] == 1 && visited.find({i,j}) == visited.end()){
                st.push({i,j});
                res++;

                while (!st.empty()){
                    auto [cx, cy] = st.top();
                    st.pop();

                    if (visited.find({cx, cy}) != visited.end()) continue;
                    visited.insert({cx, cy});

                    vect<pair<ll,ll>> n = neighbor(board,length,width,cx,cy);
                    for (const auto &p : n){
                        if (board[p.first][p.second] == 1 && visited.find(p) == visited.end()){
                            st.push(p);
                        }
                    }
                }
            }
        }
    }

    cout << res << "\n";
}


int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
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