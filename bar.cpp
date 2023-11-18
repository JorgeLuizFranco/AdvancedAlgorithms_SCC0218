#include<bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long steps = 0;

        if (k == 1) {
            cout << n << endl;
            continue;
        }

        while (n > 0) {
            if (n % k == 0) {
                n /= k;
                ++steps;
            } else {
                long long remainder = n % k;

                n -= remainder;

                steps += remainder;
            }
        }

        cout << steps << endl;
    }

    return 0;
}