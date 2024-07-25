class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > track;
        vector<int> arr;
        arr.push_back(1);
        if(rowIndex == 0){
            return arr;
        }
        track.push_back(arr);
        vector<int> arr2(2,1);
        if(rowIndex == 1){
            return arr2;
        }
        track.push_back(arr2);
        for(int i = 2;i<=rowIndex;i++){
            vector<int> ans;
            ans.push_back(1);
            for(int j = 1;j<i;j++){
                int num = track[i-1][j-1]+track[i-1][j];
                ans.push_back(num);
            }
            ans.push_back(1);
            track.push_back(ans);
        }
        return track[rowIndex];
    }
};