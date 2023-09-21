#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string tmp1, string tmp2) {
    // If tmp1 is longer than tmp2, it can't be a permutation, return false
    if (tmp1.size() > tmp2.size())
        return false;

    vector<int> tmp1v(26, 0); // Vector to store character counts in tmp1
    vector<int> tmp2v(26, 0); // Vector to store character counts in the sliding window

    // Count the characters in tmp1
    for (auto c : tmp1)
        tmp1v[c - 'a']++;

    int l = 0; // Left pointer of the sliding window
    int r = 0; // Right pointer of the sliding window

    while (r < tmp2.size()) {
        // Add the character at tmp2[r] to the window and increase right pointer
        tmp2v[tmp2[r] - 'a']++;

        // Check if the window size is equal to the length of tmp1
        if (r - l + 1 == tmp1.size()) {
            // Compare tmp1v and tmp2v using the helper function
            if (tmp1v == tmp2v)
                return true;

            // Slide the window to the right by incrementing left and right pointers
            tmp2v[tmp2[l] - 'a']--; // Remove the character at tmp2[l] from the window
            l++; // Move the left pointer to the right
        }

        r++; // Move the right pointer to the right
    }

    return false; // No permutation found, return false
}

int main() {
    string s1 = "codeforces", tm1 = "fo";
    string s2 = "hackerrank", tm2 = "ea";
    string s3 = "atcoder", tm3 = "de";
    string s4 = "vjudge", tm4 = "ug";
    string s5 = "leetcode", tm5 = "le";

    checkInclusion(tm1, s1) ? cout << "permutation of string1: TRUE" << endl : cout << "permutation of string1: FALSE" << endl;
    checkInclusion(tm2, s2) ? cout << "permutation of string2: TRUE" << endl : cout << "permutation of string2: FALSE" << endl;
    checkInclusion(tm3, s3) ? cout << "permutation of string3: TRUE" << endl : cout << "permutation of string3: FALSE" << endl;
    checkInclusion(tm4, s4) ? cout << "permutation of string4: TRUE" << endl : cout << "permutation of string4: FALSE" << endl;
    checkInclusion(tm5, s5) ? cout << "permutation of string5: TRUE" << endl : cout << "permutation of string5: FALSE" << endl;

    return 0;
}
// https://leetcode.com/problems/permutation-in-string/ (( problem link ))
