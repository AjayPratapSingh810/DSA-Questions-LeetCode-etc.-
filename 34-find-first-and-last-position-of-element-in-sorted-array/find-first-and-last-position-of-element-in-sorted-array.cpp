class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;
        int mid  = -1;
        while(i <= j){
            mid = (i+j)/2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] < target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        vector<int> ans;
        if(nums.size() == 0 || nums[mid] != target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int x = mid;
        int y = mid;
        while(x > 0 && nums[x-1] == target){
            x--;
        }
        while(y < nums.size()-1 && nums[y+1] == target){
            y++;
        }
            ans.push_back(x);
            ans.push_back(y);
        return ans;
    }
};