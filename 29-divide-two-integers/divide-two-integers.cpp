class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        long long sum = 0;
        long long divid = dividend;
        long long divis = divisor;
        bool neg = false;
        if (divid < 0 || divis < 0) {
            if(!(divid < 0 && divis < 0)){
                neg = true;
            }
            if (divid < 0) {
                divid = -divid;
            }
            if (divis < 0) {
                divis = -divis;
            }
        }
        if(divid == INT_MAX && divis == 1){
            if(neg){
                return -divid;
            }else{
                return divid;
            }
        }

        while (sum+divis <= divid) {
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