class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int size = nums2.size();
        vector<int> ans(nums1.size(),-1);
        vector<int> arr(size);
        for(int i = size-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                int top = st.top();
                arr.push_back(top);
            }else{
                arr.push_back(-1);
            }
            st.push(nums2[i]);
        }
        reverse(arr.begin(),arr.end());
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        return ans;
    }
};