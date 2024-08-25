class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        set<vector<int>> set;
        for (int i = 0; i < size - 3; i++) {
            for (int j = i + 1; j < size - 2; j++) {
                int x = j + 1;
                int y = size - 1;
                while (x < y) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[x];
                    sum += nums[y];
                    if (sum == target) {
                        set.insert({nums[i], nums[j], nums[x], nums[y]});
                        x++;
                        y--;
                    } else if (sum > target) {
                        y--;
                    } else {
                        x++;
                    }
                }
            }
        }
        vector<vector<int> > ans;
        for (const vector<int>& value : set) {
            ans.push_back(value);
        }
        return ans;
    }
};