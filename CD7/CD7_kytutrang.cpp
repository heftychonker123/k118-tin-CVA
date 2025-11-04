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
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    str n ; getline(cin , n);
    ll temp1=llmax;
    ll temp2=llmin;
    ll temp=0;
    for (const char &i : n){
        if (i!=' '){
            temp++;
        }
        else{
            temp1=min(temp1,temp);
            temp2=max(temp2,temp);
            temp++;
        }
    }
    cout << temp1 << " "<<temp2;
    return 0;
}