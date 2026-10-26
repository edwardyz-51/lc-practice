class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        ranges::sort(nums);
        return (nums.back() * nums[nums.size()-2]) - (nums.front() * nums[1]);
    }
};