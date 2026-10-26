class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>times(n);
        iota(times.begin(),times.end(), 0);
        sort(times.begin(),times.end(), [&](int a, int b){
            return tasks[a][0] < tasks[b][0]; 
        });
        int time = tasks[times.front()][0],
        processed = 0,
        ptr = 0;
        vector<int>ans;
        ans.reserve(n);
        auto lambda = [&](int a, int b){
            return tasks[a][1] == tasks[b][1] ? a > b : tasks[a][1] > tasks[b][1];
        };
        priority_queue<int,vector<int>, decltype(lambda)> pq(lambda);
        while (processed!=n){
            while (ptr < n && tasks[times[ptr]][0] <= time){
                pq.push(times[ptr++]);
            }
            if (!pq.empty()){
                ans.push_back(pq.top());
                time+=tasks[pq.top()][1]; //processing time
                pq.pop();
                processed++;
            } else {
                time = tasks[times[ptr]][0];
            }
            

        }
        return ans;
    }
};