#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map <char, int> mp;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        while (mp[s[i]] == 2) { // if we met repeated char we will move forward untill we make all chars in window equal to 1 again
            mp[s[j]]--;
            if (mp[s[j]] == 0) // erase here just to reduce memory you can add or remove as you want
                mp.erase(s[j]);
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    int longestLength = lengthOfLongestSubstring(s);
    cout << longestLength << endl;
    return 0;
}
//https://leetcode.com/problems/longest-substring-without-repeating-characters/ (( problem link ))
