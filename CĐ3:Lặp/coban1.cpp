#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; cin>>n;
    for (int i=0; i<n ; i++) cout << i+1 << " ";
    cout << endl;
    for (int i=n; i>0; i--) cout << i << " ";
    return 0;
}
