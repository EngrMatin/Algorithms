#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int f_n_0 = 1, f_n_1 = 1;
    for (int i = 2; i <= n; i++) {
        int f_n_0_new = f_n_1 + f_n_0;
        int f_n_1_new = f_n_0 + f_n_1;
        f_n_0 = f_n_0_new;
        f_n_1 = f_n_1_new;
    }

    cout << f_n_0 + f_n_1 << endl;
    return 0;
}
