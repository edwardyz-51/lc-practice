class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        vector<int> need(128, 0), window(128, 0);
        int required = 0;
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        } 
        int bestLen = INT_MAX, bestL = 0, l = 0, formed = 0;
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;
            if (need[c] > 0 && window[c] == need[c]) formed++;
            while (formed == required) {
                int curLen = r - l + 1;
                if (curLen < bestLen) {
                    bestLen = curLen;
                    bestL = l;
                }
                char leftChar = s[l];
                window[leftChar]--;
                if (need[leftChar] > 0 && window[leftChar] < need[leftChar])formed--;   
                l++;
            }
        }
        return (bestLen == INT_MAX) ? "" : s.substr(bestL, bestLen);
    }
};
