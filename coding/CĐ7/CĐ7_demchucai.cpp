#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector

int main() {
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);

    str n;
    getline(cin, n);

    map<char, int> freq;

    for (const char &i : n) {
        if (i != ' ') {
            char t = tolower(i);
            freq[t]++; // ✅ Sửa lỗi thiếu giá trị tăng
        }
    }

    for (const auto &p : freq) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}
