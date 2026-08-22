class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n ==1) return 1;
        if (n==2) return 2;
        int back_1 = 1, back_2 = 1;
        int ans;
        for (int i = 2; i <=n; ++i){
            ans = back_1+back_2;
            back_2 = back_1;
            back_1 = ans;
        }
        return ans;
            
    }
};
