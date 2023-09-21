#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int s_len = s.length();
    int p_len = p.length();

    if (s_len < p_len)
        return {};

    vector<int> freq_p(26, 0);
    vector<int> window(26, 0);

    // Initialize the frequency of characters in the pattern 'p'
    for (char c : p)
        freq_p[c - 'a']++;

    // Initialize the first window
    for (int i = 0; i < p_len; i++)
        window[s[i] - 'a']++;

    vector<int> ans;
    if (freq_p == window)
        ans.push_back(0);

    for (int i = p_len; i < s_len; i++) {
        // Slide the window to the right by removing the leftmost character
        // and adding the new character from the right side of the window
        window[s[i - p_len] - 'a']--;
        window[s[i] - 'a']++;

        if (freq_p == window)
            ans.push_back(i - p_len + 1);
    }
    return ans;
}

int main() {
    string s1 = "cbaebabacd";
    string p1 = "abc";
    vector<int> result1 = findAnagrams(s1, p1);
    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"\n";
    cout << "Anagram indices: ";
    for (int idx : result1)
        cout << "( " << idx << " )" << "  ";
    cout << "\n\n";

    string s2 = "abab";
    string p2 = "ab";
    vector<int> result2 = findAnagrams(s2, p2);
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"\n";
    cout << "Anagram indices: ";
    for (int idx : result2)
        cout << "( " << idx << " )" << "  ";
    cout << "\n\n";

    return 0;
}
// https://leetcode.com/problems/find-all-anagrams-in-a-string/ (( problem link ))
