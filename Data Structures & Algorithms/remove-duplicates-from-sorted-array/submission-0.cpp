class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int insertIndex = 1; 
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous unique element
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};
