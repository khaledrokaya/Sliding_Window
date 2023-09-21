#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    sort(begin(nums), end(nums)); // Sort the input array in ascending order

    long long currSum = 0; // Variable to keep track of the current sum of elements in the window
    long long res = 0; // Variable to store the maximum frequency of the most frequent element
    long long start = 0; // Start index of the sliding window
    long long end = 0; // End index of the sliding window

    while (end < nums.size()) {
        currSum += nums[end]; // Add the current element to the window sum

        // If it's not possible to make all elements in the window equal to the element at nums[end]
        // without exceeding the sum limit k, shrink the window from the start
        while (nums[end] * (end - start + 1) > currSum + k) {
            currSum -= nums[start];
            start++;
        }

        // Update the result with the maximum frequency of the most frequent element
        res = max(res, end - start + 1);
        end++;
    }

    return res;
}

int main() {
    vector<int> nums = { 1, 1, 2, 2, 2, 4}; // Example input
    int k = 2; // Example k

    int result = maxFrequency(nums, k);

    cout << "Frequency of the most frequent element: " << result << endl;

    return 0;
}
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/ (( problem link ))
