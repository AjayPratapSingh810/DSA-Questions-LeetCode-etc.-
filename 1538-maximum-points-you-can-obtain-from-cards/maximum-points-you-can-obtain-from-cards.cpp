class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        vector<int> arr(size);
        int sum = 0;
        for(int i= 0;i<size;i++){
            sum += cardPoints[i];
            arr[i] =sum;
        }
        if (k == size) return arr[size-1];
        int i = size-k;
        int j = 0;
        int mini = arr[i-1];
        while(i < size){
            if(mini > arr[i] - arr[j]){
                mini = arr[i] - arr[j];
            }
            i++;
            j++;
        }
        int ans = arr[size-1]-mini;
        return ans;
    }
};