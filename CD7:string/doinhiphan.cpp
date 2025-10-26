#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// Function to convert a binary string to octal using 3-bit grouping.
string binary_to_octal_cpp(string S) {
    // 1. Pad the string with leading zeros so its length is divisible by 3.
    int n = S.length();
    int remainder = n % 3;
    if (remainder != 0) {
        // Calculate the number of zeros needed: 3 - remainder
        string padding(3 - remainder, '0');
        S.insert(0, padding);
    }

    string octal_result = "";
    n = S.length(); // Update length after padding

    // 2. Iterate through the string, taking 3 bits at a time.
    for (int i = 0; i < n; i += 3) {
        // Extract the 3-bit group
        string group = S.substr(i, 3);
        
        // Convert the 3-bit binary group to its decimal/octal value.
        // Formula: (b2 * 2^2) + (b1 * 2^1) + (b0 * 2^0)
        // b2 = group[0], b1 = group[1], b0 = group[2]
        
        int octal_digit = 0;
        if (group[0] == '1') octal_digit += 4; // 100 is 4
        if (group[1] == '1') octal_digit += 2; // 010 is 2
        if (group[2] == '1') octal_digit += 1; // 001 is 1
        
        // Append the octal digit (converted to a char) to the result string.
        octal_result += to_string(octal_digit);
    }

    // 3. Handle leading zeros if the input was like "000101"
    // Find the position of the first non-zero digit
    size_t first_non_zero = octal_result.find_first_not_of('0');

    if (string::npos == first_non_zero) {
        // If the whole number is '0' (e.g., input was "000"), return "0"
        return "0";
    }

    // Return the substring starting from the first non-zero digit
    return octal_result.substr(first_non_zero);
}

// Main function for file I/O
int main() {
    // Set up file input/output redirection
    ifstream fin("NPBP.INP");
    ofstream fout("NPBP.OUT");

    if (!fin.is_open()) {
        // Fallback for direct execution/testing
        // cout << "Could not open NPBP.INP. Running test example." << endl;
        // cout << "Result: " << binary_to_octal_cpp("1010101111") << endl; // Expected: 1257
        return 0; 
    }

    string S;
    // Read the binary string
    fin >> S;
    
    // Perform the conversion and write the result
    fout << binary_to_octal_cpp(S) << endl;

    fin.close();
    fout.close();

    return 0;
}