#include <bits/stdc++.h>
using namespace std;
#define vect vector

const int MAXN = 1e5 + 1;
vect<int> tree[MAXN];
int depth[MAXN];
void bfs(int start){
    fill(&depth[0] , &depth[0] + MAXN , -1);
    queue<pair<int,int>> q;
    q.push(make_pair(start , 0));
    depth[MAXN] = 0;
    while (!q.empty()){
        
    }
}