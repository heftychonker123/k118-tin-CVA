#include <bits/stdc++.h>
using namespace std;

int countAboveAverage(const vector<long long>& arr) {
    if (arr.empty()) return 0;

    long long sum = 0;
    for (long long num : arr) {
        sum += num;
    }

    double average = static_cast<double>(sum) / arr.size();
    int count = 0;

    for (long long num : arr) {
        if (num > average) {
            count++;
        }
    }

    return count;
}
int main(){
    freopen("fibonaci.inp","r",stdin);
    freopen("fibonaci.out","w",stdout);
    int n; cin >> n;
    if (n==1) cout << 1;
    else if (n==2) cout << "1 1";
    else{
        long long a=1;
        long long b=1;
        long long temp=2;
        cout << "1 1 ";
        vector<long long> v={1,1};
        for (int i=2; i<n; i++){
            temp=a+b;
            cout << temp<< " ";
            v.push_back(temp);
            a=b; b=temp;
        }
        cout<<endl;
        cout << countAboveAverage(v);
    }
}