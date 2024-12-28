class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;
        vector<int> arr(size,0);
        int i = size - k;
        int j = 0;
        while(i < size){
            arr[j] = nums[i];
            j++;
            i++;
        }
        i  = 0;
        while(i < size-k){
            arr[j] = nums[i];
            j++;
            i++;
        }
        for(int i=0;i<size;i++){
            nums[i] = arr[i];
        }
    }
};