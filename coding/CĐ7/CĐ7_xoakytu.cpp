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
int main(){
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);

    char t;
    cin >> t;
    cin.ignore(); // Bỏ ký tự '\n' còn lại sau khi nhập t
    str s ; getline(cin , s);
    for (const char &i : s){
        if (i!=t) cout << i;
    }
    return 0;
}