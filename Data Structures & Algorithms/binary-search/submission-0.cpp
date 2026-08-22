class Solution {
public:
    int binary_search(int left, int right, vector<int>& nums, int target){
        if (left > right){
            return -1;
        }
        int m = left + (right-left) / 2;
        if (nums[m] == target) {
            return m;
        }
        if (target < nums[m]) {
            return binary_search(left, m-1, nums, target);
        } else {
            return binary_search(m+1,right, nums, target);
        }

    }
    int search(vector<int>& nums, int target) {
        return binary_search(0,nums.size(),nums,target);
    }
};
