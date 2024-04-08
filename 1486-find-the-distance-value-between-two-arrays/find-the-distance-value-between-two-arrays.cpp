class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i = 0;i<arr1.size();i++){
            int a = arr1[i];
            bool check = true;
            for(int j=0;j<arr2.size();j++){
                int diff = abs(a-arr2[j]);
                if(diff <= d){
                    check = false;
                }
            }
            if(check){
                ans++;
            }
        }
        return ans;
    }
};