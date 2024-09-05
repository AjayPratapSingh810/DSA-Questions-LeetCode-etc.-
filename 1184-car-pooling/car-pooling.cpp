class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> track(1000,0);

        for(int i=0;i<trips.size();i++){
            int c = trips[i][0];
            int f = trips[i][1];
            int t = trips[i][2];

            for(int j = f;j<t;j++){
                track[j] = track[j] + c;
                if(track[j] > capacity){
                    return false;
                }
            }
        }
        return true;
    }
};