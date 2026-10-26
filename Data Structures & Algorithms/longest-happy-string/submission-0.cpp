class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        string ans;
        int n = a + b + c;
        if (a>0) pq.push({a,'a'}); 
        if (b>0)pq.push({b,'b'});
        if (c>0) pq.push({c,'c'});
        while (ans.size() != n){
            auto [count, c] = pq.top();
            pq.pop();
            if (ans.size() >= 2 && ans.back() == c && ans[ans.size()-2]==c){
                if (pq.empty()) return ans;
                auto [count2,c2] = pq.top();
                pq.pop();
                ans.push_back(c2);
                if (count2>1) pq.push({count2-1,c2});
                pq.push({count,c});
            } else {
                ans.push_back(c);
                if (count > 1) pq.push({count-1,c});
            }

        }
        return ans;
    }
};