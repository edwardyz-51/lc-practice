class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = n;
        vector<vector<bool>>dp (n,vector<bool>(n,false));
        for (int i = 0; i < n; ++i){
            dp[i][i]=true;
        }
        for(int length = 2; length <= n; ++length){
            for(int i = 0; i + length - 1 < n; ++i){
                int j = i + length - 1;
                if (s[i]==s[j]){
                    if (length == 2 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
