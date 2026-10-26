class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), ptr = 0;
        vector<int> order(n);
        iota(order.begin(),order.end(),0);
        ranges::sort(order, [&](int a, int b){return capital[a] < capital[b];});    
        auto lambda = [&profits](int a, int b){return profits[a] < profits[b];};
        priority_queue<int,vector<int>,decltype(lambda)>pq(lambda);
        while (k){
            while (ptr < n && capital[order[ptr]] <= w) pq.push(order[ptr++]);
            if (pq.empty()) return w;
            w += profits[pq.top()];
            pq.pop();
            k--;
        }
        return w;

    }
};