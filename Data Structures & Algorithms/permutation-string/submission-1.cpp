class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char,int> s1Count;
        for (char c : s1) s1Count[c]++;

        unordered_map<char,int> window;
        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            window[s2[r]]++;

            if (r - l + 1 > s1.size()) {
                window[s2[l]]--;
                if (window[s2[l]] == 0) window.erase(s2[l]);
                l++;
            }

            if (window == s1Count) return true; 
        }
        return false;
    }
};
