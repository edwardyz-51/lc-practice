class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k>nums.size()) return {};
        int l = 0;
        vector<int> ans;
        priority_queue<pair<int,int>>window;
        for (int i = 0; i < k-1; ++i) window.push({nums[i],i});
        for (int i = k-1; i < nums.size(); ++i){
            window.push({nums[i],i});
            while (window.top().second < l){
                window.pop();
            }
            ans.push_back(window.top().first);
            l++;
        }
        return ans;
    }
};
