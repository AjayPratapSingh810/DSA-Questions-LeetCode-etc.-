class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        if(nums[nums.size()-1] < target){
            return j+1;
        }
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                j = mid-1;
            }else if(nums[mid] < target){
                i = mid+1;
            }
        }
        return i;
    }
};