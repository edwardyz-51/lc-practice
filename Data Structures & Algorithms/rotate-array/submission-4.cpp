class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> rotate(nums.begin() + n - k, nums.end());
        vector<int> tmp(nums.begin(), nums.begin() + n - k);
        rotate.insert(rotate.end(), tmp.begin(), tmp.end());
        nums = move(rotate);
    }
};