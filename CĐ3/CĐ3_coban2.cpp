#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; cin>>n;
    int a3=0;
    for (int i=0; i<=n; i+=13) cout << i << " ";
    cout << endl;
    for (int i=1; i<=n; i*=2) cout << i<< " ";
    cout << endl;
    for (int i=0; i<n; i+=7) a3=i;
    cout << a3;
    return 0;
}
