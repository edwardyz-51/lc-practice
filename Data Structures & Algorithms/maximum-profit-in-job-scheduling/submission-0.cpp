class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int MAX_END_TIME = *max_element(endTime.begin(),endTime.end());
        size_t n = endTime.size();
        vector<int>dp(MAX_END_TIME+1);
        // dp[0] = 0;
        for (size_t end(0uz); end <= MAX_END_TIME; ++end){
            for (size_t job(0uz); job < n; ++job){
                if (endTime[job] <= end){
                    dp[end] = max(dp[end], dp[startTime[job]] + profit[job]);
                }
            }
        }
        return dp[MAX_END_TIME];



        /*

        */
    }
};