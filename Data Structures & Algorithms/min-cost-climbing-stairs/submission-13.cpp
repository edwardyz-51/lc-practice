class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==0 || n == 1) return 0;
        // if (n==2) return cost[0];
        int back_2 = 0, back_1 = 0;
        int ans;
        for (int i = 2; i <= n; ++i){
            ans = min(back_2 + cost[i-2], back_1+cost[i-1]);
            back_2=back_1;
            back_1 = ans;
        }
        return ans;
    }
};
