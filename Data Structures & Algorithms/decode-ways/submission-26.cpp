class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int a = s[0] - '0', size = s.length();
        if (a==0) return 0;
        if (size==1) return 1;
        int b = s[1]-'0', dp = 1, dp2;
        if (b==0 && a>=3) return 0;
        if (b==0 || (a==2 && b>=7)) dp2 = 1; 
        else dp2 = a == 1 || a == 2 ? 2 : 1;
        if (size==2) return dp2;
        for (int i = 2; i < size; ++i){
            int dp3, cur = s[i]-'0', prev = s[i-1] - '0';
            if (cur == 0) {
                if (prev == 1 || prev == 2) dp3 = dp;
                else return 0;
            } else if (cur <= 6){
                if (prev==1 || prev==2) dp3 = dp + dp2;
                else dp3 = dp2;
            } else {
                if (prev==1) dp3 = dp + dp2;
                else dp3 = dp2;
            }
            dp = dp2;
            dp2 = dp3;       
        }
        return dp2;
    }
};

        


