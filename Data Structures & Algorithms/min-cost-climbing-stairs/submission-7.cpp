class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // if (n==2) return min(cost[0],cost[1]);
        int back_2 = 0, back_1 = 0, cur;
        for (int i = 1; i <= n; ++i){
            cur = min(back_2 + cost[i-2], back_1+cost[i-1]);
            back_2 = back_1;
            back_1 = cur;
        }
        return cur;



    }
};
