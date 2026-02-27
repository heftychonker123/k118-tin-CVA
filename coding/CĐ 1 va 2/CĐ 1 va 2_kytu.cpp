#include <bits/stdc++.h>
using namespace std;

int main(){
    char ch; cin>> ch;
    if (isdigit(ch)) cout << "SO";
    else if (isupper(ch)) cout << "HOA";
    else if (islower(ch)) cout << "THUONG";
    else cout << "DAC BIET";
}