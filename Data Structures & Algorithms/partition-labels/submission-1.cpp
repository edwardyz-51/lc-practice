class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        vector<int> count(26,0);
        for (char c : s) {count[c - 'a']++;}
        int substring = 0;
        unordered_set<int>need;
        need.insert(s[0]);
        for (char c: s){
            if (need.empty()){
                ans.push_back(substring);
                substring=0;
            }
            count[c-'a']--;
            if (count[c-'a'] > 0) need.insert(c);
            else /*if (/* count[c-'a'] ==0 && need.find(c) != need.end())*/ need.erase(c);
            substring++;
        }
        ans.push_back(substring);
        return ans;
    }
};
