class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size(), i = 0;
        vector<vector<int>>ans;
        while (i<n){
            if (i<n-1 && intervals[i][1] < intervals[i+1][0]){
                ans.push_back(intervals[i]);
            }
            else {
            vector<int> merged = intervals[i];
            while(i<n-1 && merged[1] >= intervals[i+1][0]){
                merged[0] = min(merged[0],intervals[i+1][0]);
                merged[1] = max(merged[1],intervals[i+1][1]);
                ++i;
            }
            ans.push_back(merged);
            }
            ++i;
            

        }
        return ans;
    }
};
