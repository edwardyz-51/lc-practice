class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for (int i = 0; i<nums.size(); i++){
            if (duplicate.count(nums[i])){
                return true;
            }
            duplicate.insert(nums[i]);
        }
        return false;
    }
};