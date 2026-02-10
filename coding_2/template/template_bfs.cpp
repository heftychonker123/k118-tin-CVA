#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

struct Node {
    ll label; 
    vect<Node*> neighbor;
    Node(ll l) : label(l) {}
};

void bfs_shortest_path(Node* start , Node* end) {
    map<Node*, ll> dist; // distance from start
    queue<Node*> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        for (Node* nxt : curr->neighbor) {
            if (dist.find(nxt) == dist.end()) { // not visited yet
                dist[nxt] = dist[curr] + 1;
                q.push(nxt);
            }
        }
    }

    if (dist.find(end) != dist.end()) {
        cout << dist[end] << "\n";
    } else {
        cout << -1 << "\n"; // unreachable
    }
}

int main() {
    freopen("bfs.inp" , "r" , stdin);
    freopen("bfs.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q, s, t; 
    cin >> n >> q >> s >> t;

    vect<Node*> v;
    for (int i = 0; i < n; i++) {
        v.push_back(new Node(i+1));
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;
        Node* start = v[x-1];
        Node* end   = v[y-1];
        start->neighbor.push_back(end);
        end->neighbor.push_back(start);
    }

    bfs_shortest_path(v[s-1] , v[t-1]);
}
