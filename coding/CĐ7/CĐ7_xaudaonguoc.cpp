#include <bits/stdc++.h>
using namespace std;
#define str string
#define strri string::reverse_iterator
#define stri string::iterator
int main(){
    string n ; getline(cin , n);
    strri rstart = n.rbegin();
    strri rend=n.rend();
    for (strri i=rstart ; i!=rend ; i++){
        cout << *i;
    }
    return 0;
}