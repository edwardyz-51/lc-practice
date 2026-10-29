class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>counts;
        for (int i : arr) counts[i]++;
        priority_queue<int,vector<int>,greater<>>minq;
        for (auto& [num,count]:counts)minq.push(count);
        while (k-- && !minq.empty()){
            int c = minq.top(); 
            minq.pop();
            if (c > 1) minq.push(c-1);
        }
        return minq.size();

    }
};
