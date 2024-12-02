class Solution {
public:
    double solve(double x,long long int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double ans = 0;
        if(n%2 == 0){
            ans = myPow(x*x,n/2);
        }else{
            ans = myPow(x*x,n/2)*x;
        }
        return ans;
    }
    double myPow(double x, int n) {
        bool negative = false;
        if(n < 0){
            negative = true;
        }
        long long int k = n;
        k = abs(k);
        double ans = solve(x,k);
        if(negative){
            return 1/ans;
        }
        return ans;
    }
};