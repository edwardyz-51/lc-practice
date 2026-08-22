class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int curMin = 1, curMax = 1;
        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(max(tmp, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};