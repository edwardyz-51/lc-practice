#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Optional speedup: only try word lengths that exist in the dict
        unordered_set<int> lens;
        for (const string& w : wordDict) lens.insert(w.size());

        for (int i = 1; i <= n; i++) {
            for (int len : lens) {
                int j = i - len;
                if (j < 0) continue;
                if (!dp[j]) continue;

                // check if s[j..i-1] is a word
                if (dict.count(s.substr(j, len))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
