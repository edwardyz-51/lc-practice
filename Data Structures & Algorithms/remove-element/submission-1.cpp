class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int count = nums.size(), idx = 0;
       while (idx < nums.size()){
        while (idx < nums.size() && nums[idx]==val){
            count--;
            swap(nums[idx], nums.back());
            nums.pop_back();
        }
        idx++;
       } 
       return count;
    }
};