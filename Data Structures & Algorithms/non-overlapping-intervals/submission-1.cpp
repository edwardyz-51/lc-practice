class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count  =0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); ++i){
            vector<int> cur = intervals[i];
            if (cur[0] < prev[1]){
                prev = cur[1] > prev[1] ? prev : cur;
                count++;
            } else prev = cur;
        }
        return count;
    }
};
