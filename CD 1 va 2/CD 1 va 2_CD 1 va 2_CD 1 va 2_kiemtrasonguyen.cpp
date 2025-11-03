#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    switch (a){
        case 0:
            cout << "BANG KHONG";
            break;
        default:
            if (a<0){
                if (a%2==0) cout << "AM CHAN" << endl;
                else cout << "AM LE" << endl;
            }
            if (a>0){
                if (a%2==0) cout << "DUONG CHAN"<< endl;
                else cout << "DUONG LE"<< endl;
            }
    }
    return 0;
}