#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vect vector

void backtrack(vect<bool> &chosen, ll n, str sub = "") {
    if ((ll)sub.size() == n) {
        cout << sub << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!chosen[i-1]) {
            if (sub.empty() || abs((sub.back() - '0') - i) != 1) {
                chosen[i-1] = true;
                backtrack(chosen, n, sub + to_string(i));
                chosen[i-1] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; 
    cin >> n;
    vect<bool> chosen(n, false);
    backtrack(chosen, n);
    return 0;
}
