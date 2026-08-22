class Solution {
public:
    double myPow(double x, int n) {
        if (x==0) return 0;
        if (n==0) return 1;
        double ans = pow(x,n);
        return n < 0 ? 1/ans : ans;
    }

    double pow(double x, int n){
        if (n==0) return 1;
        double ans = pow(x,n/2);
        return n&1 ? ans*ans*x : ans*ans;
    }
};
