class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>check;
        int ans = 0;
        while (true) {
            ans += pow(n%10, 2);
            n /=10;
            if (n==0) {
                if (check.count(ans)) {
                    return false;
                }
                check.insert(ans);
                if (ans == 1) {
                    return true;
                }
                n = ans;
                ans = 0;
            }
        }
        return true;
    }
};
