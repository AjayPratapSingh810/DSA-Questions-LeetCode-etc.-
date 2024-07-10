class Solution {
public:
    vector<int> solve(vector<int>& nums){
        if (nums.size() <= 1) {
            return nums;
        }

        int mid = nums.size() / 2;
        vector<int> arr1(mid);
        vector<int> arr2(nums.size() - mid);

        for (int i = 0; i < mid; ++i) {
            arr1[i] = nums[i];
        }
        for (int i = mid; i < nums.size(); ++i) {
            arr2[i - mid] = nums[i];
        }

        vector<int> leftArray = solve(arr1);
        vector<int> rightArray = solve(arr2);

        vector<int> ans;
        int start1 = 0, start2 = 0;

        while (start1 < leftArray.size() && start2 < rightArray.size()) {
            if (leftArray[start1] < rightArray[start2]) {
                ans.push_back(leftArray[start1]);
                start1++;
            } else {
                ans.push_back(rightArray[start2]);
                start2++;
            }
        }

        while (start1 < leftArray.size()) {
            ans.push_back(leftArray[start1]);
            start1++;
        }

        while (start2 < rightArray.size()) {
            ans.push_back(rightArray[start2]);
            start2++;
        }

        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans = solve(nums);
        return ans;
    }
};