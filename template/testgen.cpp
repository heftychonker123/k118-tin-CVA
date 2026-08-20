#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define fi first 
#define se second 
#define pb push_back

// HSG HN 2025 - Đèn lồng
const string filename = "*"; // Replace * with any other
const int TEST = 100;

int n;

// Init RNG
int seed = 7405;
// seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(seed);
int rnd(int l , int r){
    return abs((int)rng() % (r-l+1)) + l;
}

// Sinh testcase cho từng test

void gen_test(){
    ofstream inp(filename + ".inp");

    n = rnd(1 , 100);
    inp << n << "\n";
    for (int i = 0 ; i<n ; i++){
        int t = rnd(0 , 1);
        if (t == 0) inp << "V";
        else inp << "D";
    }
}

bool check_test(){
    return (system(("fc " + filename + ".out " + filename + ".ans").c_str()) == 0); 
}

void judge(){
    // Compile file code trâu và file code cần kiểm tra
    string compile_code = "g++ -o ";
    system((compile_code + "trau " + filename + "/trau.cpp" ).c_str());
    system((compile_code + "test " + filename + "/nop.cpp").c_str());

    for (int i = 1 ; i <= TEST ; i++){
        gen_test;
        string run_trau = string("trau.exe") + " < " + filename + ".inp" + " > " + filename + ".ans";
        string run_test = string("test.exe") + " < " + filename + ".inp" + " > " + filename + ".out";
        system(run_trau.c_str());
        system(run_test.c_str());

        if (check_test()){
            cout << "Answer matched on test case: " << i << "\n"; 
        }
        else{
            cout << "Answer differed on test case: " << i << "!\n";
            exit(0);
        }
    }
}

signed main(){
    judge();
}
