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
    str n ; getline( cin , n );
    sort(n.begin() , n.end());
    cout << n << "\n";
    sort(n.rbegin() , n.rend());
    cout << n;
    return 0;
}