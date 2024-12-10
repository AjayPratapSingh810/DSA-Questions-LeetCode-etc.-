class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int i = 0;
        int size = nums.size();
        vector<int> arr(size);
        while(i < nums.size()){
            if(nums[i] < 0){
                arr[neg] = nums[i];
                neg += 2;
            }else{
                arr[pos] = nums[i];
                pos += 2;
            }
            i++;
        }
        return arr;
        
    }
};