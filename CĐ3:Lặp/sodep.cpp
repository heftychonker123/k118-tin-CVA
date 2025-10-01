#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;
    bool ans = true;

    for (const char &letter : N) {
        if (letter != '6' && letter != '8') {
            ans = false;
            break; // optional: exit early if any invalid digit is found
        }
    }

    if (ans) cout << "YES";
    else cout << "NO";

    return 0;
}
