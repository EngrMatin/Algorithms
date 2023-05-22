#include <iostream>
using namespace std;

// Function to calculate the count of valid n-digit numbers
int countValidNumbers(int n) {
    int a = 1; // Number of n-digit numbers ending with 1
    int b = 1; // Number of n-digit numbers ending with 2

    for (int i = 2; i <= n; i++) {
        int newA = a + b; // New count of n-digit numbers ending with 1
        int newB = a;     // New count of n-digit numbers ending with 2
        a = newA;
        b = newB;
    }

    return a + b; // Total count of valid n-digit numbers
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    if (n < 1) {
        cout << "Invalid input! n must be a positive integer." << endl;
    } else {
        int count = countValidNumbers(n);
        cout << "The number of " << n << "-digit numbers that can be created using only digits 1 and/or 2, where no three identical digits stand side by side, is: " << count << endl;
    }
    return 0;
}
