class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = (l+r) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
    
    return -1;
        

    }
};