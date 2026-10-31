class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        for (size_t i(0uz); i < nums.size(); ++i){
            if (seen.count(nums[i]))
                if (i-seen[nums[i]] <= k) return true;
            
            seen[nums[i]]=i;
        }
        return false;
    }
};