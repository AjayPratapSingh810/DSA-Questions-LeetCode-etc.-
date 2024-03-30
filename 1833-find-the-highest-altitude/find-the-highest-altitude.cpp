class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int sum = 0;
        for(int i = 0;i<gain.size();i++){
            sum = sum + gain[i];
            if(sum > highest){
                highest = sum;
            }
        }
        return highest;
    }
};