#include <cstdlib>  // for system()
#include <iostream>
int main() {
    // Execute the Bash script
    int result1 = system("./cleanup.sh");
    int result2 = system("./standardize.sh");
    // Check the result
    if (result1 == 0 && result2 == 0) {
        std::cout << "Script executed successfully.\n";
    } else {
        std::cerr << "Script execution failed with code " << result1 << "\n" << result2 << "\n";
    }

    return 0;
}
