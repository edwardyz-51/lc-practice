class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>count;
        for (int i : arr) count[i]++;
        int best = -1;
        for (int i : arr) if (i==count[i] && i > best) best = i;
        return best;
    }
};