class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x){
            if (x<0 && rev < (INT_MIN - x%10)/10) return 0;
            if (x>0 && rev > (INT_MAX - x%10)/10) return 0;
            rev*=10;
            rev+=(x%10);
            x/=10;
        }
        return rev;
    }
};
