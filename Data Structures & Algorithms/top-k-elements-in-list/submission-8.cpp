class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        // {element,count of element}
        // {1,1,1}

        for (int i : nums) count[i]++;
        vector<vector<int>>frequency(nums.size());
        for (auto& [num, cnt] : count){
            frequency[cnt-1].push_back(num);
        }
        
        vector<int>ans;
        ans.reserve(k);

        for (int i = frequency.size()-1; i >= 0; --i){
            for (int num : frequency[i]){
                ans.push_back(num);
                if (ans.size()==k) return ans;
            }
        }
        return ans;

    }
};
