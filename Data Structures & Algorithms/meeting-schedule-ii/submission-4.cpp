class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        // min-heap of end times for active meetings
        priority_queue<int, vector<int>, greater<int>> pq;
        //always increasing start times
        //if the end time is before the start time, we can do on same day
        for (const auto& it : intervals) {
            if (!pq.empty() && pq.top() <= it.start) pq.pop(); 
            // reuse a room/day
            pq.push(it.end);
        }

        return pq.size();
    }
};