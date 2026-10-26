class Solution {
    const int K = 3;
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>count;
        for (int num : nums){
            count[num]++;
            if (count.size()>2){
                unordered_map<int,int> new_count;
                for (auto& [n,c] : count)
                    if (c>1) new_count[n]=c-1;
                count = new_count;
            }
        }
        vector<int>ans;
        for (auto& [n,c] : count){
            int freq = 0;
            for (int num : nums) if (num==n) freq++;
            if (freq>nums.size()/K) ans.push_back(n);
        }
        return ans;
        

    }
};