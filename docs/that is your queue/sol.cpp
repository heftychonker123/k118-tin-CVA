#include <bits/stdc++.h>
using namespace std;

int P , c;
deque<pair<int,int>> q;

void getPatient(){
    auto [l,r] = q.front(); q.pop_front();
    cout << l << '\n';
    q.push_back({l , l});
    if (l + 1 <= r) q.push_front({l+1 , r});
}

void expedite(int x){
    deque<pair<int,int>> newQ;
    while (!q.empty() && !(q.front().first <= x && x <= q.front().second)){
        newQ.push_back(q.front());
        q.pop_front();
    }

    auto [l,r] = q.front(); q.pop_front();
    if (l <= x - 1) newQ.push_back({l , x-1});
    if (x + 1 <= r) newQ.push_back({x+1 , r});

    while (!q.empty()){
        newQ.push_back(q.front());
        q.pop_front();
    }

    newQ.push_front({x,x});
    q = newQ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int currCase = 0;
    while (true){
        cin >> P >> c;
        if (P == 0 && c == 0) break;
        
        while (!q.empty()) q.pop_front();
        q.push_front({1 , P});

        cout << "Case " << ++currCase << ":\n";
        while (c--){
            char type ; cin >> type;
            if (type == 'N') getPatient();
            else if (type == 'E'){
                int x ; cin >> x;
                expedite(x);
            }
        }
    }
}

// p/s: đây là tối ưu niche nhất mà t từng nghĩ ra