#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
void check(str a , str b){
    int i=0 , j=0;
    ll length_a=a.size() , length_b=b.size();
    while (i<length_a || j<length_b){
        if (a[i]!=b[j]){
            cout << "NO" << endl;
            return;
        }
        ll ss_a=0 , ss_b=0;
        ll tempa=a[i] , tempb=b[j];
        while (a[i+ss_a]==tempa) ss_a++;
        while (b[j+ss_b]==tempb) ss_b++;
        if (ss_a>ss_b){
            cout << "NO" << endl;
            return;
        }
        i+=ss_a;
        j+=ss_b;
    }
    cout << "YES"<<endl;
    return ;
}
int main(){
    freopen("banphim.inp" , "r" , stdin);
    freopen("banphim.out" , "w" , stdout);
    ll t; cin >> t;
    for (int tc=0 ; tc<t ; tc++){
        str a , b;
        cin >> a; cin >> b;
        check(a,b);
    }
    return 0;
}