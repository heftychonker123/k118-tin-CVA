#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long>& pages, int k, long long mp) {
    int v = 1;
    long long cs = 0;
    
    for (long long page : pages) {
        if (cs + page <= mp) {
            cs += page;
        } else {
            v++;
            cs = page;
            if (v > k) return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("novel.inp", "r", stdin);
    freopen("novel.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<long long> pages(n);
    long long tp = 0;
    long long mc = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
        tp += pages[i];
        mc = max(mc, pages[i]);
    }
    
    long long left = mc;
    long long right = tp;
    long long result = right;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (check(pages, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}