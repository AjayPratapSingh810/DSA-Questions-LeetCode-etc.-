class Solution {
public:
    bool listsAreEqual(list<int>& list1, list<int>& list2) {
        // If sizes are different, lists are not equal
        if (list1.size() != list2.size()) {
            return false;
        }

        // Create iterators for both lists
        auto it1 = list1.begin();
        auto it2 = list2.begin();

        // Iterate over elements and compare
        while (it1 != list1.end()) {
            // If corresponding elements are not equal, lists are not equal
            if (*it1 != *it2) {
                return false;
            }
            // Move iterators to the next element
            ++it1;
            ++it2;
        }

        // If all elements are equal, lists are equal
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, list<int>> mpRow;
        unordered_map<int, list<int>> mpCol;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                mpRow[i].push_back(grid[i][j]);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                mpCol[i].push_back(grid[j][i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for(int j=0;j<grid.size();j++){
                if (listsAreEqual(mpRow[i], mpCol[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
};