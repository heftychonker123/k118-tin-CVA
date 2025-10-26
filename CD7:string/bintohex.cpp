#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define strri string::reverse_iterator

void solve(str n) {
    unordered_map<string, char> binToHex = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };

    // Pad with '0' to make length a multiple of 4
    while (n.size() % 4 != 0) n = '0' + n;

    str hex = "";
    for (size_t i = 0; i < n.size(); i += 4) {
        str chunk = n.substr(i, 4);
        hex += binToHex[chunk];
    }
    while (hex.size() > 1 && hex[0] == '0') hex.erase(0, 1);

    cout << hex << '\n';
}

int main() {
    freopen("npms.inp" , "r" , stdin); 
    freopen("npms.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str n; cin >> n;
    solve(n);
    return 0;
}
