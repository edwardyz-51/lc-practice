class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxF = 0, ans = 0;
        unordered_map<char,int>freq;
        for (int i = 0; i < s.size(); ++i){
            freq[s[i]]++;
            maxF=max(maxF,freq[s[i]]);
            while (i-l-maxF+1 > k){
                freq[s[l]]--;
                l++;
            }
            ans = max (ans,i-l+1);
        }
        return ans;
    }
};
