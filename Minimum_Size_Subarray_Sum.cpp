#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int sum{}, r{}, l{}, ans = INT_MAX; // Initialize variables for sum, right pointer, left pointer, and answer.

    for (int i = 0; i < nums.size(); i++) { // Loop through the array with index 'i'.
        sum += nums[r]; // Add the value at right pointer 'r' to the current sum.
        
        while (sum >= target) { // If the sum is greater than or equal to the target.
            ans = min(ans, r - l + 1); // Update the minimum length found so far (ans) by comparing with the current window size.
            sum -= nums[l]; // Remove the value at left pointer 'l' from the current sum.
            l++; // Move the left pointer to the right to shrink the window.
        }

        r++; // Move the right pointer to the right to expand the window.
    }

    return (ans == INT_MAX) ? 0 : ans; // Return the minimum length found, or 0 if no valid subarray is found.
}

int main() {
    // Test cases
    vector<int> nums1 = { 2, 3, 1, 2, 4, 3 };
    int target1 = 7;
    cout << "Minimum length of subarray with sum >= " << target1 << ": " << minSubArrayLen(target1, nums1) << endl;

    vector<int> nums2 = { 1, 4, 4 };
    int target2 = 4;
    cout << "Minimum length of subarray with sum >= " << target2 << ": " << minSubArrayLen(target2, nums2) << endl;

    vector<int> nums3 = { 1, 1, 1, 1, 1, 1, 1, 1 };
    int target3 = 11;
    cout << "Minimum length of subarray with sum >= " << target3 << ": " << minSubArrayLen(target3, nums3) << endl;

    vector<int> nums4 = { 10, 5, 8, 1, 4, 6 };
    int target4 = 15;
    cout << "Minimum length of subarray with sum >= " << target4 << ": " << minSubArrayLen(target4, nums4) << endl;

    vector<int> nums5 = { 1, 2, 3, 4, 5 };
    int target5 = 11;
    cout << "Minimum length of subarray with sum >= " << target5 << ": " << minSubArrayLen(target5, nums5) << endl;

    return 0;
}
// https://leetcode.com/problems/minimum-size-subarray-sum/ (( problem link ))
