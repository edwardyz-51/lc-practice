class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        size_t n = days.back();
        vector<int>dp(n+2,0);
        int ptr = days.size()-1;
        for (int i = n; i >=0; --i){
            if (i == days[ptr]) {
                ptr--;
                dp[i]=min({dp[i+1] + costs[0],
                (i+7 <= n ? dp[i+7] : 0) + costs[1],
                (i+30 <= n ? dp[i+30] : 0) + costs[2]});
            } else dp[i]=dp[i+1];
            if (ptr==-1) return dp[i];
            
        }
        return dp[0];
    }
};