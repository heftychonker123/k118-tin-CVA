#include <bits/stdc++.h>
using namespace std;

int main(){
    int time; cin>>time;
    if (0<=time&& time<=5) cout << "Đêm khuya";
    else if (6<=time&&time<=11) cout << "Buổi sáng";
    else if (12<=time&&time<=17) cout << "Buổi chiều";
    else if (18<=time&&time<=23) cout << "Buổi tối";
    else cout << "Giờ không hợp lệ";
    return 0;
}