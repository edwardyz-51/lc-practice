class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(),intervals.end());
        int idx = 0, n = intervals.size();
        vector<vector<int>>ans;
        while(idx < n && newInterval[0] > intervals[idx][1]){
            ans.push_back(intervals[idx]);
            idx++;
        }
        while (idx < n && intervals[idx][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0],intervals[idx][0]);
            newInterval[1] = max(newInterval[1],intervals[idx][1]);
            idx++;
        }
        ans.push_back(newInterval);
        while(idx<n){
            ans.push_back(intervals[idx]);
            idx++;
        }
        return ans;

    }
};
