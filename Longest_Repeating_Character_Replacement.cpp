#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; int k; cin >> s >> k; // string , int max num that we can replace
    int n = s.length(), res = 0;
    int start = 0, end = 0, maxFreq = 0;
    map<int, int> freq;
    for (end = 0; end < n; end++) {
        freq[s[end]]++;
        maxFreq = max(maxFreq, freq[s[end]]);
        // len-maxFreq <= k, we have to find if the substring has atmost k different characters which we alter to make all the characters of the string equal
        while (end - start + 1 - maxFreq > k) { // so here if we met different char and we cant change it we will remove previous char in string and start new freq
            freq[s[start]]--;
            start++;
        }
        res = max(res, end - start + 1);
    }
    cout << res << endl;
    return 0;
}
// https://leetcode.com/problems/longest-repeating-character-replacement/ (( problem link ))
