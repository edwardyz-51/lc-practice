class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>map;
        for (int i : nums){
            map[i]++;
        }
        priority_queue<pair<int,int>>heap;
        for (const auto&pair : map){
            heap.push({pair.second,pair.first});
        }
        for (int i = 0; i<k; ++i){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
