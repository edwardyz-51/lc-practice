class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for (int i : nums) count[i]++;
        vector<int>ans; 
        vector<vector<int>>freq(nums.size()+1);
        ans.reserve(k);
        for (auto& [a,b] : count){
            freq[b].push_back(a);
        }

        for (int i = freq.size()-1; i>=0; --i){
            for (int j = 0; j < freq[i].size();++j){
                ans.push_back(freq[i][j]);
                if (ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
