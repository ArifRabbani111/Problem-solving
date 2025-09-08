/*No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*main function*/
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int A = 1; A < n; ++A){
            int B = n - A;
            if((to_string(A) + to_string(B)).find('0') == string::npos){
                return {A, B};
            }
        }
        return {};
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Test function
void testSolution() {
    Solution solution;
    
    // Test cases
    vector<int> testCases = {2, 11, 10000, 69, 1010};
    
    cout << "Testing No-Zero Integers Solution:" << endl;
    cout << "===================================" << endl;
    
    for(int n : testCases) {
        vector<int> result = solution.getNoZeroIntegers(n);
        cout << "n = " << n << " -> ";
        printVector(result);
        
        // Verify the result
        if(!result.empty()) {
            int sum = result[0] + result[1];
            bool hasZero = (to_string(result[0]) + to_string(result[1])).find('0') != string::npos;
            cout << "  Verification: " << result[0] << " + " << result[1] << " = " << sum;
            cout << (sum == n ? " ✓" : " ✗");
            cout << (hasZero ? " (contains zero ✗)" : " (no zeros ✓)") << endl;
        }
        cout << endl;
    }
}

int main() {
    testSolution();
    
    // Interactive testing
    cout << "\nEnter a number to find No-Zero integers (0 to exit): ";
    int n;
    Solution solution;
    
    while(cin >> n && n > 0) {
        vector<int> result = solution.getNoZeroIntegers(n);
        cout << "Result for " << n << ": ";
        printVector(result);
        cout << "\nEnter another number (0 to exit): ";
    }
    
    cout << "Goodbye!" << endl;
    return 0;
}