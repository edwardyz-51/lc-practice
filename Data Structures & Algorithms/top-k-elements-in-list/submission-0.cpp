class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> frequency(nums.size()+1);

        for (int n : nums){
            count[n]++;
        }
        for (const auto& a : count){
            frequency[a.second].push_back(a.first); //frequency[count].push_back(n)
        }
        vector<int> ans;
        for (int i = frequency.size()-1;i>0;--i){
            for(int n : frequency[i]){
                ans.push_back(n);
                if (ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
