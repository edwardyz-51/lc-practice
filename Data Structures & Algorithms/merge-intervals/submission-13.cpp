class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            int prev = output.back()[1];
            if (start <= prev) 
                output.back()[1] = max(prev, end);
            else 
                output.push_back({start, end});
            
        }
        return output;
    }
};