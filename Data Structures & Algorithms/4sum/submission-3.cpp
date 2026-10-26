class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        ranges::sort(nums);
        int n = nums.size();
        for (size_t i{0uz}; i < n; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (size_t j=i+1; j<n; ++j){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j+1, r = n-1;
                int a = nums[i], b = nums[j];
                while (l < r) {
                    int c = nums[l], d = nums[r];
                    long long sum = (long long )a + b + c + d;
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        ans.push_back({a,b,c,d});
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};