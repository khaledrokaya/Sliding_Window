#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0; // If the array is empty, no profit can be made.

    int maxProfit = 0;
    int minPrice = prices[0]; // Initialize the minimum price as the first day's price.

    for (int i = 1; i < n; i++) {
        // Update the maximum profit if the current day's price minus the minimum price is greater.
        maxProfit = max(maxProfit, prices[i] - minPrice);

        // Update the minimum price if the current day's price is smaller.
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main() {
    // Test cases
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max profit from buying and selling stock 1: " << maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max profit from buying and selling stock 2: " << maxProfit(prices2) << endl;

    vector<int> prices3 = {3, 8, 2, 5, 1, 6};
    cout << "Max profit from buying and selling stock 3: " << maxProfit(prices3) << endl;

    return 0;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/  (( problem_link ))
