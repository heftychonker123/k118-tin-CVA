#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
struct Update {
    int day, id, change;
};

int main() {
    int n; long long G;
    cin >> n >> G;
    vector<Update> logs(n);
    for (int i=0;i<n;i++) cin >> logs[i].day >> logs[i].id >> logs[i].change;
    sort(logs.begin(), logs.end(), [](auto &a, auto &b){ return a.day < b.day; });

    map<int,long long> milk;
    set<int> leaders;
    long long maxMilk = G;
    for (auto &u: logs) milk[u.id] = G;
    for (auto &[id,val]: milk) leaders.insert(id);

    int changes = 0;
    for (auto &u: logs) {
        milk[u.id] += u.change;
        long long newMax = 0;
        for (auto &[id,val]: milk) newMax = max(newMax,val);
        set<int> newLeaders;
        for (auto &[id,val]: milk) if (val==newMax) newLeaders.insert(id);
        if (newLeaders != leaders) {
            changes++;
            leaders = newLeaders;
        }
    }
    cout << changes << "\n";
}
