class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>counts;
        for (int i : arr) counts[i]++;
        priority_queue<int,vector<int>,greater<>>minq;
        int ans = 0;
        for (auto& [num,count]:counts)minq.push(count);
        while (k && !minq.empty()){
            int c = minq.top(); 
            if (c>k) ans++;
            minq.pop();
            k-=min(c,k);
        }
        return ans + minq.size();

    }
};
