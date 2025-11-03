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
    str a ; getline(cin , a);
    str b ; getline(cin , b);
    char state='=';
    if (a.length()>b.length()) state='>';
    else if (a.length() < b.length()) state='<';
    else{
        ll c=a.compare(b);
        if (c>0) state='>';
        if (c<0) state='<';
    }
    cout << "A " << state << " B"; 
    return 0;
}