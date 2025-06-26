#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;  // To keep track of the current value of the subsequence
        int cnt = 0; // To count the length of the valid subsequence
        int bits = 32 - __builtin_clz(k); // Calculate the number of bits needed to represent k
        
        // Iterate through the string from right to left (LSB to MSB)
        for(int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i]; // Get the i-th character from the end
            
            if(ch == '1') {
                // Only consider adding this '1' if:
                // 1. We're within the bit length of k (i < bits)
                // 2. Adding this bit won't make the value exceed k
                if(i < bits && sm + (1LL << i) <= k) {
                    sm += (1LL << i); // Add 2^i to the sum
                    cnt++;            // Increment the count
                }
            } else {
                // Always safe to add '0's as they don't increase the value
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "1001010";
    int k1 = 5;
    cout << "Example 1:" << endl;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << solution.longestSubsequence(s1, k1) << endl; // Expected: 5
    
    // Example 2
    string s2 = "00101001";
    int k2 = 1;
    cout << "\nExample 2:" << endl;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << solution.longestSubsequence(s2, k2) << endl; // Expected: 6
    
    // Additional test case
    string s3 = "1111";
    int k3 = 1;
    cout << "\nAdditional Test Case:" << endl;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << solution.longestSubsequence(s3, k3) << endl; // Expected: 1 (only the last '1' or '0's if any)
    
    return 0;
}