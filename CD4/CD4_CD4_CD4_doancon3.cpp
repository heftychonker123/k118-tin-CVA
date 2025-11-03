#include <bits/stdc++.h>
using namespace std;

#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back

int main(){
    int n; cin >> n;
    vector <long long> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    long long max_sum = 0, current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum = max(0LL, current_sum + v[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
    return 0;
}