#include <bits/stdc++.h>
using namespace std;

int main(){
    long double n; cin >> n;
    long double sum = 0;
    vector<long double> v = {};
    for (long long i = 0; i < n; i++){
        long double t; cin >> t;
        sum += t;
        v.push_back(t);
    }
    long double average =  sum / n;
    long double diff = pow(10.0L, 6);
    long double ans = 0;
    for (const long double i : v){
        if (abs(i - average) < diff){
            diff = abs(i - average);
            ans = i;
        }
    }
    cout << fixed << setprecision(2);
    cout << average << endl;
    cout << ans;
}
