#include <bits/stdc++.h>
using namespace std;

int main(){
    char c; cin >> c;
    if (isupper(c)){
        cout<< char(tolower(c))<<endl;
    }
    else cout << char(toupper(c))<<endl;
    return 0;
}