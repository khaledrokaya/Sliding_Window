#include <iostream>
#include <algorithm>
using namespace std;
int minFlips(string s) {
    int n = s.size();
    s += s; // Extend the string to consider cyclic nature

    // Create two alternating patterns: "010101..." and "101010..."
    string o, r;
    for (int i = 0; i < s.size(); i++) {
        o += (i % 2) ? '0' : '1';
        r += (i % 2) ? '1' : '0';
    }

    int nO = 0, nR = 0, ans = INT_MAX;
    for (int i = 0; i < s.size(); i++) {
        // Count the number of differences between s and the alternating patterns
        if (o[i] != s[i]) ++nO;
        if (r[i] != s[i]) ++nR;

        if (i >= n) { // The most left element is outside of the sliding window, we need to subtract the ans if we did 'flip' before.
            if (o[i - n] != s[i - n]) --nO;
            if (r[i - n] != s[i - n]) --nR;
        }

        if (i >= n - 1) // After reaching a window of size n, update the minimum number of flips needed.
            ans = min({ nO, nR, ans });
    }

    return ans; // Return the minimum number of flips
}

int main() {
    string s1 = "111000";
    string s2 = "01001001101";
    string s3 = "10001100101000000";
    string s4 = "0101010";
    string s5 = "101010";

    int result1 = minFlips(s1);
    int result2 = minFlips(s2);
    int result3 = minFlips(s3);
    int result4 = minFlips(s4);
    int result5 = minFlips(s5);

    cout << "Minimum Number of Flips for s1: " << result1 << endl;
    cout << "Minimum Number of Flips for s2: " << result2 << endl;
    cout << "Minimum Number of Flips for s3: " << result3 << endl;
    cout << "Minimum Number of Flips for s4: " << result4 << endl;
    cout << "Minimum Number of Flips for s5: " << result5 << endl;

    return 0;
}
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/ (( problem link ))
