class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        long long sum = 0;
        long long divid = dividend;
        long long divis = divisor;
        bool neg = false;
        if (dividend == 0)
            return 0;
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend == -2147483648)
                return 2147483647;
            return -dividend;
        }
        if (divid < 0 || divis < 0) {
            if (!(divid < 0 && divis < 0)) {
                neg = true;
            }
            if (divid < 0) {
                divid = -divid;
            }
            if (divis < 0) {
                divis = -divis;
            }
        }

        while (sum + divis <= divid) {
            sum = sum + divis;
            ans++;
            if (ans > INT_MAX) {
                if (neg) {
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }
        if (neg) {
            ans = -ans;
        }
        return ans;
    }
};