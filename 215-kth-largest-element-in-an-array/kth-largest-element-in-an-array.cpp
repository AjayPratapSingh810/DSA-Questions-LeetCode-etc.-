class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a = 0;
        int ans = -1;
        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();
            a++;
            if(a == k){
                ans = ele;
            }
        }
        return ans;
    }
};