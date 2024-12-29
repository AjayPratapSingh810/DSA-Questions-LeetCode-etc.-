class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        bool flag = false;
        while(i > 0){
            if(nums[i] > nums[i-1]){
                int m = INT_MAX;
                int f = i-1;
                for(int l = i;l<nums.size();l++){
                    if(nums[l] < m && nums[l] > nums[i-1]){
                        m = nums[l];
                        f = l;
                    }
                }
                swap(nums[i-1],nums[f]);
                sort(nums.begin()+i,nums.end());
                flag = true;
                break;
            }
            i--;
        }
        if(!flag){
            sort(nums.begin(),nums.end());
        }
    }
};