class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // 1. Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) { //while end < newstart
            result.push_back(intervals[i]);
            i++;
        }
        //the last loop ended prob because the current interval ends after the new interval starts
        //starting from when the last while loop ended:
        // 2. Merge all overlapping intervals with newInterval
        //while the start of the current interval were looking at is less than the end of the newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) { //while curstart <=newend 
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // 3. Add the merged interval
        result.push_back(newInterval);

        // 4. Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
