class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp2;

        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]] = true;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]] = true;
        }

        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<nums1.size();i++){
            if(mp2[nums1[i]] != true){
                arr1.push_back(nums1[i]);
                mp2[nums1[i]] = true;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(mp1[nums2[i]] != true){
                arr2.push_back(nums2[i]);
                mp1[nums2[i]] = true;
            }
        }

        vector<vector<int>> ans;
        ans.push_back(arr1);
        ans.push_back(arr2);
        return ans;
    }
};