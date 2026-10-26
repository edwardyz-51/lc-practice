class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        size_t n = days.back();
        vector<int>dp(n+31,0);
        int ptr = days.size()-1;
        //dp[i] = min cost to attend all days from i... end
        for (int i = n; i >=0; --i){
            if (ptr >= 0 && i == days[ptr]) {
                ptr--;
                dp[i] = dp[i+1] + costs[0];
                dp[i]=min(dp[i],dp[i+7] + costs[1]);
                dp[i]=min(dp[i],dp[i+30]+ costs[2]);
            } else dp[i]=dp[i+1];
            
        }
        return dp[0];
    }
};