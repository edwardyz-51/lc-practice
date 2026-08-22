class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty prefix is segmentable
        for (int length = 1; length <= n; length++) {
            for (int j = 0; j < length; j++) {
                if (dp[j] == false) continue; // can't reach j, so skip
                // if s[j..i-1] is a dictionary word, we can reach i
                if (dict.count(s.substr(j, length - j))) {
                    dp[length] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};