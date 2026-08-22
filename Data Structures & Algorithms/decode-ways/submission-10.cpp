class Solution {
public:
    int numDecodings(string s) {
        //from back
        /*
        case 1: n = 1-6. ->          case 1.1: n-1 = 0 or 3-9. S(n-2) ways
                                     case 1.2: n-1 = 1 or 2. S(n-1) + S(n-2) ways

        case 2: n = 7-9. ->          case 2.1: n-1 = 0 or 2-9. S(n-2) ways
                                     case 2.2: n-1 = 1. S(n-1) + S(n-2) ways

        case 3: n = 0 ->             case 3.1: n-1 = 1 or 2. S(n-1) ways
                                     case 3.2: n-1 = 0, 3-9. 0 ways
        */
        

        int a = s[0] - '0';
        if (a==0) return 0;
        if (s.length()==1) return 1;
        int b = s[1]-'0';
        if (b==0 && (a>=3 || a==0)) return 0;
        vector<int> dp(s.length());
        dp[0] = 1; 
        if (b==0 || (a==2 && b>=7)) dp[1] = 1;
        else dp[1] = ((a == 1 || a == 2) ? 2 : 1);
        if (s.length()==2) return dp[1];
        for (int i = 2; i < s.length(); ++i){
            int cur = s[i]-'0';
            int prev = s[i-1] - '0';
            if (cur <= 6 && cur >=1){
                if (prev==1 || prev==2) dp[i] = dp[i-2] + dp[i-1];
                else dp[i] = dp[i-1];
            } else if (cur >= 7 && cur <= 9){
                if (prev==1) dp[i] = dp[i-2] + dp[i-1];
                else dp[i] = dp[i-1];
            } else if (cur == 0) {
                if (prev == 1 || prev == 2) dp[i] = dp[i-2];
                else return 0;
            }       
        }
        return dp[s.length()-1];

    }
};

