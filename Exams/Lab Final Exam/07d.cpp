#include <iostream>
using namespace std;

int countNumbers(int n) {
    // Initialize count for n = 1 and n = 2
    int count1 = 2; // 1, 2
    int count2 = 3; // 11, 12, 21

    // Update count for n > 2
    for (int i = 3; i <= n; i++) {
        int newCount = count1 + count2; // Count for i is sum of count for i-1 and count for i-2
        count1 = count2; // Update count for i-1 to count for i-2
        count2 = newCount; // Update count for i-2 to count for i
    }

    return count2; // Final count for n
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int count = countNumbers(n);
    cout << "The number of " << n << "-digit numbers: " << count << endl;

    return 0;
}
