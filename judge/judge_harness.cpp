#include <bits/stdc++.h>
using namespace std;
#define str string

string trim(const string& s) {
    if (s.empty()) return s;
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

int main() {
    // Xóa file output cũ
    remove("test_case\\ex.out");
    
    // Compile target.cpp
    int compileStatus = system("g++ target.cpp -o target.exe");
    if (compileStatus != 0) {
        cerr << "❌ Compilation of target.cpp failed.\n";
        return 1;
    }
    
    // Run executable
    int runStatus = system("target.exe < test_case\\input.inp > test_case\\ex.out");
    if (runStatus != 0) {
        cerr << "❌ Execution of target.exe failed. Exit code: " << runStatus << "\n";
        return 1;
    }
    
    // Compare output
    ifstream to_check("test_case\\ex.out");
    ifstream check("test_case\\output.out");
    
    if (!to_check.is_open() || !check.is_open()) {
        cerr << "❌ Failed to open one or more files for comparison.\n";
        return 1;
    }
    
    str a, b;
    bool match = true;
    int line_num = 1;
    
    while (getline(to_check, a) && getline(check, b)) {
        str a_trimmed = trim(a);
        str b_trimmed = trim(b);
        
        if (a_trimmed != b_trimmed) {
            cerr << "❌ Mismatch at line " << line_num << ":\n";
            cerr << "Expected line: \"" << b_trimmed << "\"\n";
            cerr << "Output line:   \"" << a_trimmed << "\"\n";
            match = false;
            break;
        }
        line_num++;
    }
    
    if (getline(to_check, a)) {
        cerr << "❌ Output file has more lines than expected (extra line " << line_num << "): \"" << trim(a) << "\"\n";
        match = false;
    }
    if (getline(check, b)) {
        cerr << "❌ Expected file has more lines than output (missing line " << line_num << "): \"" << trim(b) << "\"\n";
        match = false;
    }
    
    to_check.close();
    check.close();
    
    if (match) {
        cout << "✅ Output matches expected answer.\n";
        return 0;
    } else {
        cout << "❌ Output does NOT match expected answer.\n";
        return 1;
    }
}
