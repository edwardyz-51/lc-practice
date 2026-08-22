class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = (int)s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty prefix is segmentable

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) continue; // can't reach j, so skip

                // if s[j..i-1] is a dictionary word, we can reach i
                if (dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};