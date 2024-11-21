class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;

        while(i<j){
            while(i< nums.size() && nums[i] == 0){
                i++;
            }
            while(j >= 0 && nums[j] != 0){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        i = 0;
        while(i < nums.size() && nums[i] == 0){
            i++;
        }
        j = nums.size()-1;
        while(i<j){
            while(i< nums.size() && nums[i] == 1){
                i++;
            }
            while(j >= 0 && nums[j] != 1){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
    }
};