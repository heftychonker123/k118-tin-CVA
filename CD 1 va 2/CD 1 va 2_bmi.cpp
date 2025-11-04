#include <bits/stdc++.h>
using namespace std;

int main(){
    double weight,height ; cin >> height >> weight;
    float bmi= (weight/(height*height));
    cout << setprecision(2)<<fixed<<bmi<< " - ";
    if (bmi<18.5) cout << "Gầy";
    else if (bmi<25) cout << "Bình thường";
    else if (bmi<30) cout << "Thừa cân";
    else cout << "Béo phì";
    return 0;
}