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
//initialization code
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    str n; getline(cin , n);
    vect<int> mark(10,0);
    for (const char &i : n){
        if (isdigit(i)){
            mark[(int) i-'0']++;
        }
    }
    for (int i=0 ; i<10 ; i++){
        cout << mark[i] << " ";
    }
    return 0;
}