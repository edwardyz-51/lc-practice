class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>A(nums.size());
        ranges::iota(A,0);
        auto lambda = [&nums](int a, int b){
            return nums[a]==nums[b] ? a > b : nums[a]>nums[b];
        };
        priority_queue<int,vector<int>,decltype(lambda)>pq(A.begin(),A.end(),lambda);
        for (size_t i(0uz); i < k; ++i){
            int tmp = pq.top();
            pq.pop();
            nums[tmp]*=multiplier;
            pq.push(tmp);
        }
        return nums;
    }
};