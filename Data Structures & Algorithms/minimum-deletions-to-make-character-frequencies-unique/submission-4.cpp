class Solution {
public:
    int minDeletions(string s) {
        int count[26]={0}, ans = 0;
        for (char c : s) count[c-'a']++;
        vector<int>bucket(s.size()+1);
        for (size_t i(0uz); i < 26; ++i) if (count[i]) bucket[count[i]]++;
        for (int i = s.size(); i > 0; --i){
            while(bucket[i]>1) {
                bucket[i-1]++;
                bucket[i]--;
                ans++;
            }
        }
        return ans;

    }
};
