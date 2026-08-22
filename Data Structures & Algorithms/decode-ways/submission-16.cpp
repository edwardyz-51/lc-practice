class Solution {
public:
    int numDecodings(string s) { // a = s[0], b = s[1]
        int a = s[0] - '0';
        if (a==0) return 0; //first element is 0, so no possible decode.
        if (s.length()==1) return 1;
        int b = s[1]-'0';
        if (b==0 && a>=3) return 0; //if the second element is 0, and the first element is 3 or more, no possible decoding.
        int dp = 1, dp2;
        if (b==0 || (a==2 && b>=7)) dp2 = 1; 
        //if the second element is 0 OR if the second element is greater than or equal to 7, and 
        //the first element is 2 (27,28,29 can't be interpreted as 1 character) there is only 1 way to decode (treat them separately)
        else dp2 = ((a == 1 || a == 2) ? 2 : 1);
        // if the first element is 1 or 2, there are 2 ways to decode. else, one way.
        if (s.length()==2) return dp2;
        for (int i = 2; i < s.length(); ++i){
            int dp3;
            int cur = s[i]-'0';
            int prev = s[i-1] - '0';
            if (cur <= 6 && cur >=1){
                if (prev==1 || prev==2) dp3 = dp + dp2;
                else dp3 = dp2;
            } else if (cur >= 7 && cur <= 9){
                if (prev==1) dp3 = dp + dp2;
                else dp3 = dp2;
            } else if (cur == 0) {
                if (prev == 1 || prev == 2) dp3 = dp;
                else return 0;
            }
            dp = dp2;
            dp2 = dp3;       
        }
        return dp2;

    }
};
        //from back
        /*
        case 1: n = 1-6. ->          case 1.1: n-1 = 0 or 3-9. S(n-2) ways
                                     case 1.2: n-1 = 1 or 2. S(n-1) + S(n-2) ways

        case 2: n = 7-9. ->          case 2.1: n-1 = 0 or 2-9. S(n-2) ways
                                     case 2.2: n-1 = 1. S(n-1) + S(n-2) ways

        case 3: n = 0 ->             case 3.1: n-1 = 1 or 2. S(n-1) ways
                                     case 3.2: n-1 = 0, 3-9. 0 ways
        */
        


