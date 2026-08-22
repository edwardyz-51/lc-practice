class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProduct = nums[0];
        vector<vector<int>>dp(n,vector<int>(n));
        for (int i = 0; i<n; ++i){ // [0][0] = -2, [1][1] = -1
            dp[i][i] = nums[i];
            maxProduct = maxProduct > nums[i] ? maxProduct : nums[i];
        }
        for (int length = 1; length < n; ++length){
            cout << "length: " << length << endl;
            for (int i = 0; i+length < n; ++i){ // i = starting index, i + length = ending index
                cout << i << ": ";
                dp[i][i+length] = dp[i][i+length-1] * nums[i+length]; //dp[0][1] = dp[0][0] * nums[1] so -2 * -1 = 2
                cout << dp[i][i+length] << " = " << dp[i][i+length-1] << " * " << nums[i+length] << endl;
                maxProduct = maxProduct > dp[i][i+length] ? maxProduct : dp[i][i+length];
            }
        }
        return maxProduct;
    }
};
