#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
bool visited[MAXN];

void dfs(int n){
    if (visited[n]) return;
    visited[n] = true;
    for (int i = 1 ; i*i <= n ; i++){
        if (n%i == 0){
            int j = n/i;
            dfs((i-1)*(j+1));
        }
    }
}

int main(){
    int n ; cin >> n;
    dfs(n);
    int count = 0;
    for (int i = 0 ; i<n ; i++){
        if (visited[i]) count++;
    }
    cout << count << "\n";
    for (int i = 0 ; i<n ; i++){
        if (visited[i]) cout << i << " ";
    }
}