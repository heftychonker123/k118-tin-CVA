#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;

    string result;
    int count = 0;

    // Duyệt từ phải sang trái
    for (int i = N.size() - 1; i >= 0; i--) {
        result += N[i];
        count++;
        // Sau mỗi 3 chữ số, nếu chưa đến đầu chuỗi thì thêm dấu chấm
        if (count % 3 == 0 && i != 0) {
            result += '.';
        }
    }

    // Đảo ngược kết quả để đúng thứ tự
    reverse(result.begin(), result.end());

    cout << result << endl;
    return 0;
}
