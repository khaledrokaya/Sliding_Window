#include <iostream>
#include <string>
#include <climits>
using namespace std;

const int no_of_chars = 26;

// Function to find the smallest window containing all characters of 'pat'
string findSubString(string str, string pat) {
    int len1 = str.length();
    int len2 = pat.length();

    // Check if the length of the string is less than the pattern's length
    // If yes, then no such window can exist
    if (len1 < len2) {
        return "No such window exists";
    }

    // Hash tables to store the occurrence of characters in the pattern and string
    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };

    // Store the occurrence of characters in the pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i] - 'a']++;

    int start = 0, start_index = -1, min_len = INT_MAX;

    // Start traversing the string
    // Count of characters in the current window
    int count = 0;
    for (int j = 0; j < len1; j++) {
        // Count occurrence of characters in the current window
        hash_str[str[j] - 'a']++;

        // If the current character is present in the pattern,
        // and its count in the current window is less than or equal to its count in the pattern,
        // increment the character count in the window
        if (hash_str[str[j] - 'a'] <= hash_pat[str[j] - 'a'])
            count++;

        // If all characters in the pattern are matched in the current window
        if (count == len2) {
            // Try to minimize the window by moving the start index
            while (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'] || hash_pat[str[start] - 'a'] == 0) {
                if (hash_str[str[start] - 'a'] > hash_pat[str[start] - 'a'])
                    hash_str[str[start] - 'a']--;
                start++;
            }

            // Update the minimum window size and the start index of the minimum window
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    // If no window found
    if (start_index == -1) {
        return "No such window exists";
    }

    // Return the substring starting from start_index with length min_len
    return str.substr(start_index, min_len);
}

// Driver code
int main() {
    string str1 = "abcdef";
    string pat1 = "cde";
    cout << "Input: str = \"" << str1 << "\", pat = \"" << pat1 << "\"\n";
    cout << "Smallest window: " << findSubString(str1, pat1) << "\n\n";

    string str2 = "aaabbbccc";
    string pat2 = "abc";
    cout << "Input: str = \"" << str2 << "\", pat = \"" << pat2 << "\"\n";
    cout << "Smallest window: " << findSubString(str2, pat2) << "\n\n";

    string str3 = "abbbaccccbbbca";
    string pat3 = "abc";
    cout << "Input: str = \"" << str3 << "\", pat = \"" << pat3 << "\"\n";
    cout << "Smallest window: " << findSubString(str3, pat3) << "\n\n";

    string str4 = "a";
    string pat4 = "a";
    cout << "Input: str = \"" << str4 << "\", pat = \"" << pat4 << "\"\n";
    cout << "Smallest window: " << findSubString(str4, pat4) << "\n\n";

    string str5 = "abc";
    string pat5 = "xyz";
    cout << "Input: str = \"" << str5 << "\", pat = \"" << pat5 << "\"\n";
    cout << "Smallest window: " << findSubString(str5, pat5) << "\n\n";

    return 0;
}
// https://leetcode.com/problems/minimum-window-substring/ (( problem  link ))
