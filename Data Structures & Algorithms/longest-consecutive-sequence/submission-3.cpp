class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int ans = 0;
        for (int i : nums){
            if (seen.count(i-1)) continue;
            int count = 1;
            while (seen.count(i+1)){
                count++;
                i++;
            }
            ans = max (ans,count);
        }
        return ans;
    }
};
