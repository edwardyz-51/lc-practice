class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans = nums;
        ans.insert(ans.end(),ans.begin(),ans.end());
        return ans;
    }
};