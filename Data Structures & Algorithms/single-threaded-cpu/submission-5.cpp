class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int>times(n);
        iota(times.begin(),times.end(), 0);
        sort(times.begin(),times.end(), [&](int a, int b){
            return tasks[a][0] < tasks[b][0]; 
        });
        auto lambda = [&tasks](int a, int b){
            return tasks[a][1] == tasks[b][1] ? a > b : tasks[a][1] > tasks[b][1];
        };
        long long time = tasks[times.front()][0],ptr = 0;
        vector<int>ans;
        ans.reserve(n);
        priority_queue<int,vector<int>, decltype(lambda)> pq(lambda);
        while (ans.size()!=n){
            while (ptr < n && tasks[times[ptr]][0] <= time)
                pq.push(times[ptr++]);
            if (!pq.empty()){
                ans.push_back(pq.top());
                time+=tasks[pq.top()][1];
                pq.pop();
            } 
            else time = tasks[times[ptr]][0];
        }
        return ans;
    }
};