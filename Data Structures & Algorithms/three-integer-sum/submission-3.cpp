class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        //so we can identify if we are adding duplicates or to eliminate cases
        vector<vector<int>> res;

        for (int i = 0; i <nums.size(); i++) {
            if (nums[i]>0) break; //if nums[i]>0, all future numbers will be positive, so no sum to 0
            if (i>0 && nums[i] == nums[i-1]) continue; //skips duplicates

            int l = i + 1;
            int r = nums.size()-1; //l is right after i, r is at the end (greatest value)
            while (l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum>0) { //sum is too large, shift r left to get smaller value
                    r--;
                } else if (sum<0) { //sum too low, shift l right to get bigger value
                    l++;
                } else { //sum ==0, pass
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++; //look for new pairs
                    r--;
                     while (l < r && nums[l] == nums[l - 1]) { //skip duplicate l's
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
