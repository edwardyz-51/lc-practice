class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c)->bool{
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int l = 0, ans = 0, count = 0;
        for (int r = 0; r < s.size(); ++r){
            if (r-l==k){
                ans = max(count,ans);
                if (isVowel(s[l++])) count--;
            }
            if (isVowel(s[r]))count++;
        }
        ans = max(count,ans);
        return ans;
    }
};
