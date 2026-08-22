class Solution {
public:
    double myPow(double x, int n) {
        double ans = pow(x,n);
        return n < 0 ? 1/ans : ans;
    }

    double pow(double x, int n){
        if (n==0) return 1;
        double ans = pow(x,n/2);
        ans *= ans;
        if (n&1) ans*=x;
        return ans;
    }
};
