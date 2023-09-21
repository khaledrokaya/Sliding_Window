#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> win; // Create a map to store the substrings of length 10 and their occurrence count.
    int l{}, r = 10; // Initialize left pointer to 0 and right pointer to 10 (to get the first 10-letter substring).

    for (int i = 0; i < s.length(); i++) { // Loop through the string to find all 10-letter substrings.
        if (r > s.length()) break; // If the right pointer goes beyond the string length, break the loop.
        string tmp = s.substr(l, 10); // Get the current 10-letter substring.

        if (win.find(tmp) == win.end()) { // Check if the substring is already present in the map.
            win[tmp] = 0; // If not, add it to the map with occurrence count initialized to 0.
        }
        else {
            win[tmp]++; // If the substring is already present, increment its occurrence count.
        }
        l++; // Move the left pointer to slide the window to the right.
        r++; // Move the right pointer to slide the window to the right.
    }

    vector<string> ans; // Create a vector to store the repeated DNA sequences.
    for (auto& i : win) { // Loop through the map.
        if (win[i.first]) { // If the occurrence count of a substring is greater than 0, it means it's repeated.
            ans.push_back(i.first); // Add the repeated DNA sequence to the answer vector.
        }
    }
    return ans; // Return the vector containing repeated DNA sequences.
}

int main() {
    // Test cases
    string dna1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result1 = findRepeatedDnaSequences(dna1);
    cout << "Repeated DNA sequences in the given string 1:" << endl;
    for (const string& sequence : result1) {
        cout << sequence << ' '; // Print the repeated DNA sequences found in the given string 1.
    }
    cout << endl;

    string dna2 = "AAAAAAAAAAAAA";
    vector<string> result2 = findRepeatedDnaSequences(dna2);
    cout << "Repeated DNA sequences in the given string 2:" << endl;
    for (const string& sequence : result2) {
        cout << sequence << ' '; // Print the repeated DNA sequences found in the given string 2.
    }
    cout << endl;

    string dna3 = "AGTAGTAGTAGTAGTAGT";
    vector<string> result3 = findRepeatedDnaSequences(dna3);
    cout << "Repeated DNA sequences in the given string 3:" << endl;
    for (const string& sequence : result3) {
        cout << sequence << ' '; // Print the repeated DNA sequences found in the given string 3.
    }
    cout << endl;

    return 0;
}
// https://leetcode.com/problems/repeated-dna-sequences/ (( problem link ))
