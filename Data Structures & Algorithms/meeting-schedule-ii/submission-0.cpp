class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by start time
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { 
                 return a.start < b.start; 
             });

        // Min-heap for end times
        priority_queue<int, vector<int>, greater<int>> pq;

        // Add the first meeting’s end time
        pq.push(intervals[0].end);

        // Process the rest
        for (int i = 1; i < intervals.size(); ++i) {
            // If we can reuse a room (day)
            if (intervals[i].start >= pq.top()) {
                pq.pop();   // Meeting in this room finished
            }
            pq.push(intervals[i].end);
        }

        // Heap size = number of rooms needed
        return pq.size();
    }
};
