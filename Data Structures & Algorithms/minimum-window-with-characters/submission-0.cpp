#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        // ASCII counts
        vector<int> need(128, 0), window(128, 0);
        int required = 0; // number of distinct chars we must satisfy
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        }

        int formed = 0; // how many distinct chars currently satisfied
        int bestLen = INT_MAX, bestL = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            // just reached enough of this char
            if (need[c] > 0 && window[c] == need[c]) {
                formed++;
            }

            // if valid window, shrink it
            while (formed == required) {
                int curLen = r - l + 1;
                if (curLen < bestLen) {
                    bestLen = curLen;
                    bestL = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                // removing leftChar broke validity
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar]) {
                    formed--;
                }
                l++;
            }
        }

        return (bestLen == INT_MAX) ? "" : s.substr(bestL, bestLen);
    }
};
