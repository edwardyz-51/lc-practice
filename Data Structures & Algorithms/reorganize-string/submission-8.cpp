class Solution {
public:
    string reorganizeString(string s) {
        array<int,26> count {0};
        int n = s.size();
        for (char c : s){
            count[c-'a']++;
            if (count[c-'a'] > n+1/2 + 1) return "";
        }
        priority_queue<pair<int,int>>pq;
        for (int i = 0; i < 26; ++i){
            if (!count[i]) continue;
            pq.push({count[i], i+'a'});
        }
        string ans;
        ans.reserve(n);
        while (!pq.empty()){
            auto [count, c] = pq.top();
            pq.pop();
            if (!ans.empty() && c==ans.back()) {
                if (pq.empty()) return "";
                auto [count2,c2] = pq.top();
                pq.pop();
                ans.push_back(c2);
                if (count2>1)pq.push({count2-1,c2});
                pq.push({count,c});
            } else {
                ans.push_back(c);
                if (count>1) pq.push({count-1,c});
            }
        }
        return ans;
    }
};