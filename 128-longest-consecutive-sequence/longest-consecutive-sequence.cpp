class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        int count = 1;
        int prev = pq.top();
        pq.pop();
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            if(top-prev == 0){
                prev = top;
            }
            else if(top- prev == 1){
                prev = top;
                count++;
            }else{
                if(count > ans){
                    ans = count;
                }
                count = 1;
                prev = top;
            }
        }
        if(count > ans){
                    ans = count;
                }
        return ans;
    }
};