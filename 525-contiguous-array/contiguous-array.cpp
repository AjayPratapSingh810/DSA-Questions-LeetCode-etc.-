class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;

        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                count = count+1;
            }else{
                count = count-1;
            }
            if(mp.find(count) != mp.end()){
                maxLength = max(maxLength,i-mp[count]);
            }else{
                mp[count]=i;
            }
        }
        return maxLength;

    }
};