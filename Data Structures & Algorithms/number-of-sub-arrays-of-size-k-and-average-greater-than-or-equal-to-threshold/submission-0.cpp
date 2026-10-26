class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = -1, r = 0, n = arr.size();
        int sum = 0, ans = 0;
        for (; r < k-1; ++r) sum+=arr[r];
        while (r < n){
            sum+= arr[r++];
            if (l>=0) sum-=arr[l];
            l++;
            if ((sum/k)>=threshold) ans++;
        }
        return ans;
    }
};