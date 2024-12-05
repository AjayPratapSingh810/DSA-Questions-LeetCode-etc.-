class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int a = nums1[i];
            int j = 0;
            for(j;j<nums2.size();j++){
                if(nums2[j] == a){
                    break;
                }
            }
            int greater = -1;
            for(int k = j+1;k<nums2.size();k++){
                if(nums2[k] > a){
                    greater = nums2[k];
                    break;
                }
            }
            ans.push_back(greater);
        }
    return ans;
    }
};