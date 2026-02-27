#include <bits/stdc++.h>
using namespace std;
double a[100] , b[100] , kq , kqc , dlminbt;
int c[100] , d[100] , m , n , k , t , i;
string s;

double tinh(double a , double b , int d){
    if (d==1) return a+b;
    if (d==2) return a-b;
    if (d==3) return a*b;
    if (d==4) return a/b;
}