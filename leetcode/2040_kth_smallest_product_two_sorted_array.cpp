#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while (low < high) {
                int mid = (low + high) / 2;
                long long prod = 1LL * num1 * nums2[mid];
                if (prod <= target) {
                    if (num1 > 0) low = mid + 1;
                    else high = mid;
                } else {
                    if (num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }

            count += (num1 > 0) ? low : (nums2.size() - low);
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 5};
    vector<int> nums2 = {3, 4};
    int k = 2;
    cout << "Example 1 Output: " << sol.kthSmallestProduct(nums1, nums2, k) << endl; // Expected: 8

    // Example 2
    nums1 = {-4, -2, 0, 3};
    nums2 = {2, 4};
    k = 6;
    cout << "Example 2 Output: " << sol.kthSmallestProduct(nums1, nums2, k) << endl; // Expected: 0

    // Example 3
    nums1 = {-2, -1, 0, 1, 2};
    nums2 = {-3, -1, 2, 4, 5};
    k = 3;
    cout << "Example 3 Output: " << sol.kthSmallestProduct(nums1, nums2, k) << endl; // Expected: -6

    return 0;
}
/*Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.*/
/*solution:Binary Search Setup:

The kthSmallestProduct function uses binary search on the possible product values (from -1e10 to 1e10).

For each midpoint mid, it checks how many products are less than or equal to mid using the countProducts function.

Counting Products:

The countProducts function iterates over each element in nums1. For each num1:

If num1 is zero, all products with nums2 will be zero. If target >= 0, all these products are counted.

For non-zero num1, it performs a binary search on nums2 to find how many products num1 * nums2[j] are <= target. The direction of the binary search depends on whether num1 is positive or negative.

Binary Search in nums2:

For num1 > 0, the products increase as nums2[j] increases. So, we find the rightmost nums2[j] such that num1 * nums2[j] <= target.

For num1 < 0, the products decrease as nums2[j] increases. So, we find the leftmost nums2[j] such that num1 * nums2[j] <= target.

Edge Cases:

Handles zero in nums1 separately since multiplying zero with any number in nums2 gives zero.

Correctly adjusts the binary search direction based on the sign of num1.

Efficiency:

The binary search in kthSmallestProduct runs in O(log(2e10)) iterations.

Each countProducts call is O(n log m) where n is the size of nums1 and m is the size of nums2.

Overall complexity is O(n log m log (max_product)), which is efficient for the constraints.*/