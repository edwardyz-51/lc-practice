#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        // Store queries with original indices: {query_value, original_index}
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Min-heap stores: {interval_size, right_boundary}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vector<int> ans(queries.size());
        int i = 0; // Pointer for intervals
        
        for (const auto& [q, originalIdx] : sortedQueries) {
            // 1. Add all valid intervals that start <= query
            while (i < intervals.size() && intervals[i][0] <= q) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }
            
            // 2. Remove intervals that end < query
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }
            
            // 3. Get the smallest available size
            if (!minHeap.empty()) {
                ans[originalIdx] = minHeap.top().first;
            } else {
                ans[originalIdx] = -1;
            }
        }
        
        return ans;
    }
};
