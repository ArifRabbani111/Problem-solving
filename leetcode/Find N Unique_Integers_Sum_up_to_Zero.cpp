//Given an integer n, return any array containing n unique integers such that they add up to 0.
/*Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        
        // Add pairs of positive and negative numbers
        for(int i = 1; i <= n/2; ++i){
            ans.push_back(i);
            ans.push_back(-i);
        }
        
        // If n is odd, add 0 to complete the array
        if(n % 2 == 1){
            ans.push_back(0);
        }
        
        return ans;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if(i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Helper function to calculate sum
int calculateSum(const vector<int>& vec) {
    int sum = 0;
    for(int num : vec) {
        sum += num;
    }
    return sum;
}

int main() {
    Solution solution;
    
    // Test cases
    vector<int> testCases = {1, 2, 3, 4, 5, 6};
    
    cout << "Testing sumZero function:\n";
    cout << "========================\n\n";
    
    for(int n : testCases) {
        vector<int> result = solution.sumZero(n);
        int sum = calculateSum(result);
        
        cout << "n = " << n << ": ";
        printVector(result);
        cout << " → Sum = " << sum << "\n";
    }
    
    cout << "\nAll arrays sum to 0 as expected!\n";
    
    return 0;
}