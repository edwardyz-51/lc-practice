class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0, prev1 = 1;
        for (int i = 1; i <= n; ++i){
            int cur = prev2+prev1;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
