class Solution {
public:
    void solve(int n,int &ans){
        if(n == 0){
            ans++;
            return;
        }
        if(n >= 2){
            solve(n-2,ans);
        }
        if(n >= 1){
            solve(n-1,ans);
        }
    }
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        int a = 1;
        int b = 2;
        int c = a+b;
        for(int i = 3;i <= n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};