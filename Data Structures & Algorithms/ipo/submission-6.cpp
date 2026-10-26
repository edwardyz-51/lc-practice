class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        size_t n = profits.size(), ptr = 0;
        vector<size_t> order(n);
        iota(order.begin(),order.end(),0);
        ranges::sort(order, [&](size_t a, size_t b){return capital[a] < capital[b];});    
        auto lambda = [&profits](size_t a, size_t b){return profits[a] < profits[b];};
        priority_queue<size_t,vector<size_t>,decltype(lambda)>pq(lambda);
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