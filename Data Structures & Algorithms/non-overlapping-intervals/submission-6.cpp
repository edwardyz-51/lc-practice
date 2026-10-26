class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int prev = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] < prev){
                count++;
                prev = intervals[i][1] > prev ? prev : intervals[i][1];
            } else prev = intervals[i][1];
        }
        return count;
    }
};
