class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), ptr = 0;
        vector<int>times(n);
        iota(times.begin(),times.end(), 0);
        ranges::sort(times,[&](int a, int b){ return tasks[a][0] < tasks[b][0]; });
        auto lambda = [&tasks](int a, int b){ 
            return tasks[a][1] == tasks[b][1] ? a > b : tasks[a][1] > tasks[b][1]; 
            };
        long long time = tasks[times.front()][0];
        vector<int>ans;
        ans.reserve(n);
        priority_queue<int,vector<int>, decltype(lambda)> pq(lambda);
        while (ans.size()!=n){
            while (ptr < n && tasks[times[ptr]][0] <= time)
                pq.push(times[ptr++]);
            if (!pq.empty()){
                int idx = pq.top();
                pq.pop();
                ans.push_back(idx);
                time+=tasks[idx][1];
            } 
            else time = tasks[times[ptr]][0];
        }
        return ans;
    }
};