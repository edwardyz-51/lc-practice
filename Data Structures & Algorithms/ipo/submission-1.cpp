class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = 0, n = profits.size();
        vector<int> order(n);
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(), [&](int a, int b){
            return capital[a] < capital[b];
        });    
        int ptr = 0;
        auto lambda = [&profits](int a, int b){
            return profits[a] < profits[b];
        };
        priority_queue<int,vector<int>,decltype(lambda)>pq(lambda);
        
        while (ptr < n && capital[order[ptr]] <= w) pq.push(order[ptr++]);
        while (k && !pq.empty()){
            w += profits[pq.top()];
            pq.pop();
            k--;
            while (ptr < n && capital[order[ptr]] <= w) pq.push(order[ptr++]);
        }
        return w;

    }
};