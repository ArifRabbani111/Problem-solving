#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int max_len = 1;
    int current_len = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            current_len++;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            current_len = 1;
        }
    }
    cout << max_len << endl;
    return 0;
}