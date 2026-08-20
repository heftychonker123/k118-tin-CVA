#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double

struct Point{
    db x , y;

    Point(int m , int n){x = m ; y = n;}
};

struct Line{
    Point p1 , p2;
    db a = (p1.y - p2.y);
    db b = (p2.x - p1.x);
    db c = -(p1.x * p2.y - p2.x * p1.y);
    
    bool checkCollinear(Point& p3){
        return ((p3.y - p1.x) * (p2.x - p1.x) - (p3.x - p1.x) * (p2.y - p1.y)) == 0;
    }

    int intersect(Line& d){
        db D = a*d.b - d.a * b;
        db Dx = c * d.b - d.c * b;
        db Dy = a * d.c - d.a * c;

        if (D == 0 && Dx == 0 && Dy == 0) return 1; //Trùng
        else if (D == 0) return 2; // Song song
        else return 3; // Cắt nhau
    }
};

struct Polygon{
    vector<Point> points;

    db area(){
        db res = 0;
        int n = points.size();
        for (int i = 0 ; i<n ; i++){
            res += (points[i].x * points[(i+1)%n].y - 
                    points[(i+1)%n].x * points[i].y);
        }

        return res/2;
    }
};