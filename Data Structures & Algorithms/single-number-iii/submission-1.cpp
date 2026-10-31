class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0, a = 0, b = 0;
        for (int num : nums) diff^=num;
        diff = diff & -diff;
        for (int num : nums) num&diff?a^=num :b^=num;
        return {a,b};
    }
};