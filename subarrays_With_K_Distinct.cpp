#include <bits/stdc++.h>
using namespace std;
long long subarraysWithKDistinct( vector<long long> nums, int k, int n) {
    map <long long, long long> mp;
    long long j = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;
        while (mp.size() > k) {
            mp[nums[j]]--;
            if (mp[nums[j]] == 0)
                mp.erase(nums[j]);
            j++;
        }
        ans += i - j + 1;
    }
    return ans;
}
int main() {
    int n, k; cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long ans = subarraysWithKDistinct(arr, k, n);
    cout << ans;
    return 0;
}

/* https://codeforces.com/group/isP4JMZTix/contest/380008/problem/D */
