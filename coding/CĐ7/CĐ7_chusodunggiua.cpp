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
    str n ; cin >> n;
    if (n.size() % 2 ==0) cout << "NOT FOUND";
    else{
        ll mid = (n.size()-1)/2;
        cout << n[mid];
    }
    return 0;
}