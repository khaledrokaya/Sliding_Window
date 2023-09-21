#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Deque to store indices of elements in the window
    vector<int> ans; // Vector to store the result
    int n = nums.size(); // Total number of elements in the input vector

    // Check for invalid input
    if (n == 0 || k <= 0 || k > n) {
        return ans; // Return an empty vector for invalid inputs
    }

    // Process the first sliding window of size k
    for (int i = 0; i < k; i++) {
        // Remove indices of elements that are less than the current element
        // from the back of the deque as they won't be the maximum elements
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i); // Add the current element's index to the back of the deque
    }

    ans.push_back(nums[dq.front()]); // The front of the deque contains the index of the maximum element

    // Slide the window and find maximums for the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        if (i - dq.front() >= k) {
            dq.pop_front(); // If the front element of the deque is outside the current window, remove it
        }

        // Remove indices of elements that are less than the current element
        // from the back of the deque as they won't be the maximum elements
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i); // Add the current element's index to the back of the deque
        ans.push_back(nums[dq.front()]); // The front of the deque contains the index of the maximum element
    }

    return ans; // Return the vector containing maximums for each sliding window
}

int main() {
    int k = 3;
    vector<int> arr = { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> ans = maxSlidingWindow(arr, k);

    // Print the result
    cout << "Result for k = 3: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";

    // Test Case 1: Empty array
    k = 2;
    arr = {};
    ans = maxSlidingWindow(arr, k);
    cout << "Result for an empty array: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";

    // Test Case 2: k > array size
    k = 10;
    arr = { 1, 2, 3, 4, 5 };
    ans = maxSlidingWindow(arr, k);
    cout << "Result for k > array size: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";

    // Test Case 3: Negative elements
    k = 2;
    arr = { -2, -5, -3, -8, -1 };
    ans = maxSlidingWindow(arr, k);
    cout << "Result for negative elements: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";

    // Test Case 4: k = 1
    k = 1;
    arr = { 10, 5, 8, 3, 7 };
    ans = maxSlidingWindow(arr, k);
    cout << "Result for k = 1: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n\n";

    return 0;
}
// https://leetcode.com/problems/sliding-window-maximum/ (( problem link ))
