class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest = 0, end = 0, jumps = 0;
        for (size_t i{0uz}; i < nums.size()-1; ++i){
            if (end >= nums.size()-1) break;
            furthest = max(furthest,nums[i]+(int)i);
            if (i==end) {
                jumps++;
                end = furthest;
            }
        }
        return jumps;
    }
};
