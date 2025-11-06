#include <cstdlib>  // for system()
#include <iostream>
int main() {
    // Execute the Bash script
    int result1 = system("./cleanup.sh");
    if (result1!=0) std::cout << "Cleanup.sh executed unsuccessfully with return code " << result1;
    int result2 = system("./standardize.sh");
    if (result2!=0) std::cout << "Standardize.sh executed unsuccessfully with return code " << result2;
    int result3 = system("./gitpush.sh");
    if (result3!=0) std::cout << "Git-push executed unsuccessfully with return code " << result3;
    return 0;
}
