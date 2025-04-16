class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int s = 0;
        int e = nums.size() - 1;
        int mid = (s + e) / 2;
        vector<int> a(mid + 1);
        vector<int> b(e - mid);
        for (int i = 0; i <= mid; i++) {
            a[i] = nums[i];
        }
        for (int j = mid + 1; j <= e; j++) {
            b[j - (mid + 1)] = nums[j];
        }
        vector<int> v1 = sortArray(a);
        vector<int> v2 = sortArray(b);
        int i = 0;
        int j = 0;
        vector<int> ans(nums.size());
        int r = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                ans[r++] = v1[i++];
            } else {
                ans[r++] = v2[j++];
            }
        }
        while (i < v1.size()) {
            ans[r++] = v1[i++];
        }
        while (j < v2.size()) {
            ans[r++] = v2[j++];
        }
        return ans;
    }
};