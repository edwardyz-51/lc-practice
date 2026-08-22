class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int ans = 0;
        for (int i : nums){
            if (seen.find(i-1) == seen.end()){
                int count = 1;
                while (seen.find(i+count)!=seen.end()) count++;
                ans = max (ans,count);
            }  
        }
        return ans;
    }
};
