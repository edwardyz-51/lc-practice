class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c)->bool{
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int l = 0, ans = 0, count = 0;
        for (int r = 0; r < s.size(); ++r){
            if (isVowel(s[r]))count++;
            if (r-l+1==k){
                ans = max(count,ans);
                if (isVowel(s[l++])) count--;
            }
        }
        return ans;
    }
};
