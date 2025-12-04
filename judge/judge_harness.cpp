#include <bits/stdc++.h>
using namespace std;
#define str string

// Helper function để trim whitespace
string trim(const string& s) {
    if (s.empty()) return s;
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

int main() {
    // Step 0: Xóa file output cũ để tránh false positive
    remove("test_case/ex.out");
    
    // Step 1: Compile target.cpp
    int compileStatus = system("g++ target.cpp -o target");
    if (compileStatus != 0) {
        cerr << "❌ Compilation of target.cpp failed.\n";
        return 1;
    }
    
    // Step 2: Run the compiled executable
    int runStatus = system("./target < test_case/input.inp > test_case/ex.out");
    if (runStatus != 0) {
        cerr << "❌ Execution of target failed.\n";
        
        // Kiểm tra đúng cách process exit như thế nào
        if (WIFEXITED(runStatus)) {
            cout << "Return code: " << WEXITSTATUS(runStatus) << "\n";
        } else if (WIFSIGNALED(runStatus)) {
            cout << "Killed by signal: " << WTERMSIG(runStatus) << "\n";
        } else {
            cout << "Process terminated abnormally\n";
        }
        return 1;  // ✅ Fixed: return error code thay vì 0
    }
    
    // Step 3: Compare output with expected answer
    ifstream to_check("test_case/ex.out");
    ifstream check("test_case/output.out");
    
    if (!to_check.is_open()) {
        cerr << "❌ Could not open ex.out\n";
    }
    if (!check.is_open()) {
        cerr << "❌ Could not open output.out\n";
    }
    
    if (!check.is_open() || !to_check.is_open()) {
        cerr << "❌ Failed to open one or more files for comparison.\n";
        return 1;
    }
    
    str a, b;
    bool match = true;
    int line_num = 1;
    
    while (getline(to_check, a) && getline(check, b)) {
        // Trim whitespace để so sánh chính xác hơn (optional: comment out nếu cần strict)
        str a_trimmed = trim(a);
        str b_trimmed = trim(b);
        
        if (a_trimmed != b_trimmed) {
            cerr << "❌ Mismatch at line " << line_num << ":\n";
            
            // Find first differing character
            size_t min_len = min(a_trimmed.size(), b_trimmed.size());
            size_t diff_pos = 0;
            
            while (diff_pos < min_len && a_trimmed[diff_pos] == b_trimmed[diff_pos]) {
                diff_pos++;
            }
            
            if (diff_pos < min_len) {
                cerr << "Difference starts at character position: " << diff_pos + 1 << "\n";
                
                // ✅ Fixed: Kiểm tra bounds trước khi access
                if (diff_pos < b_trimmed.size()) {
                    cerr << "Expected: '" << b_trimmed[diff_pos] << "' (ASCII " << (int)b_trimmed[diff_pos] << ")\n";
                } else {
                    cerr << "Expected: (line ended)\n";
                }
                
                if (diff_pos < a_trimmed.size()) {
                    cerr << "Output:   '" << a_trimmed[diff_pos] << "' (ASCII " << (int)a_trimmed[diff_pos] << ")\n";
                } else {
                    cerr << "Output:   (line ended)\n";
                }
            } else {
                cerr << "Lines differ in length but match up to shorter line.\n";
            }
            
            // Hiển thị full line để debug
            cerr << "Expected line: \"" << b_trimmed << "\"\n";
            cerr << "Output line:   \"" << a_trimmed << "\"\n";
            
            match = false;
            break;
        }
        line_num++;
    }
    
    // Kiểm tra xem có file nào còn dòng không
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