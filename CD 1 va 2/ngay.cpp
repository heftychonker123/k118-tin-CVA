#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    bool ans=false;
    if (n%400==0) ans=true;
    else if (n%4==0 && n%100!=0) ans=true;
    return ans;
}
int main(){
    int month,year; cin >> month >> year;
    if (month==0||year==0||month>12) cout << "INVALID";
    else{
        if (month==2){
            if (check(year)) cout << "29";
            else cout << "28";
        }
        else{
            if (month>7){
                if (month%2==0) cout << "31";
                else cout << "30";
            }
            else{
                if (month%2==0) cout << "30";
                else cout << "31";
            }
        }
    }
}