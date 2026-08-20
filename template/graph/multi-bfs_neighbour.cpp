#include <bits/stdc++.h>
using namespace std;

#define vect vector

const int MAXN = 1e5 + 1;
vect<int> graph[MAXN];
int label[MAXN];
int depth[MAXN];
struct Node{
    int a,l;
    Node(int x , int y): a(x) , l(y){};
};

int bfs(vect<int>& start){
    fill(&depth[0] , &depth[0] + MAXN , -1);
    fill(&label[0] , &label[0] + MAXN , -1);
    queue<Node> q;
    for (int i : start){
        depth[i] = 0;
        label[i] = i;
        q.push(Node(i , label[i]));
    }

    while (!q.empty()){
        auto curr = q.front() ; q.pop();
        for (int n : graph[curr.a]){
            if (label[n] == -1){
                label[n] = curr.l;
                depth[n] = depth[curr.a] + 1;
                q.push(Node(n, curr.l));

            }
            else if (label[n] == curr.l) continue;
            else return depth[curr.a] + depth[n] + 1;
        }
    }
    return -1;
}

signed main(){
    int n,m,k ; cin >> n >> m >> k;
    for (int i = 0 ; i<m ; i++){
        int a,b ; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vect<int> start(k);
    for (int i = 0 ; i<k ; i++) cin >> start[i];
}