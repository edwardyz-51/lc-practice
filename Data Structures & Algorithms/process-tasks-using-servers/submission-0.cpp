class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // Available: {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<>> available;

        // Busy: {finish time, index}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, greater<>> busy;

        for (int i = 0; i < servers.size(); ++i)
            available.emplace(servers[i], i);

        vector<int> ans(tasks.size());
        long long time = 0;

        for (int i = 0; i < tasks.size(); ++i) {
            time = max(time, (long long)i);

            // If none are available, wait for the next completion.
            if (available.empty())
                time = max(time, busy.top().first);

            // Release every server that has finished.
            while (!busy.empty() && busy.top().first <= time) {
                auto [finish, idx] = busy.top();
                busy.pop();
                available.emplace(servers[idx], idx);
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;
            busy.emplace(time + tasks[i], idx);
        }

        return ans;
    }
};