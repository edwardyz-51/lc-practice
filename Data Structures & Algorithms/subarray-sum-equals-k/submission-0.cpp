class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix; //{sum, frequency}
        prefix[0]=1;
        //sum - prefix = k
        int sum = 0, ans = 0;
        for (int num : nums){
            sum+=num;
            ans+=prefix[sum-k];
            prefix[sum]++;
        }
        return ans;
    }
};