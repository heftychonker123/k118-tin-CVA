#include <bits/stdc++.h>
using namespace std;

bool check_equal(int a,int b,int c){
    return (a==b || b==c || c==a);
}

bool check_triangle(int a, int b, int c){
    return not(a>=b+c || b>=c+a || c>=a+b);
}

bool check_regular(int a, int b, int c){
    return (a==b && a==c);
}

bool check_right(int a , int b , int c){
    return ((a*a==b*b+c*c)||(b*b==a*a+c*c)|| (c*c==a*a+b*b));
}

int main(){
    long double a,b,c; cin>>a>>b>>c;
    if (check_triangle(a,b,c)){
        if (check_regular(a,b,c)) cout << "DEU";
        else if (check_equal(a,b,c)) cout << "CAN";
        else if (check_right(a,b,c)) cout << "VUONG";
        else cout << "THUONG";
    }
    else cout << "INVALID";
    return 0;
}