#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long total_sum = n * (n + 1) / 2;
    long long given_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long num;
        cin >> num;
        given_sum += num;
    }
    cout << total_sum - given_sum << endl;
    return 0;
}