class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> mp;

        int i = 0;
        int j = 0;

        while(j < nums.size() && i< nums.size()){
            if(mp.find(nums[j]) != mp.end()){
                while(j<nums.size()){
                    if(mp.find(nums[j]) == mp.end()){
                        swap(nums[i],nums[j]);
                        mp[nums[i]] = true;
                        break;
                    }else{
                        j++;
                    }
                }
            }else{
                mp[nums[i]] = true;
            }
            i++;
        }
        return mp.size();
         
    }
};