class Solution {
public:
    int solve(int val){
        int a = val;
        int sum = 0;
        while(a>0){
            int num = a%10;
            sum = sum+(num*num);
            a = a/10;
        }
        return sum;
    } 
    bool isHappy(int n) {
        
        int slow = n;
        int fast = n;

        do{
            fast = solve(solve(fast));
            slow = solve(slow);

            if(fast == 1 || slow == 1){
                return true;
            }
            if(fast == slow){
                return false;
            }
        }while(slow != fast);
        return false;
    }
};