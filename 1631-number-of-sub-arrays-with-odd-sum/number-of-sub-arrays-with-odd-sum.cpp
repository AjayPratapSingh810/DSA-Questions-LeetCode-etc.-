class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int result = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            if(sum % 2 == 0){
                result += odd;
                even++;
            }else{
                result += even;
                odd++;
            }
            result = result%1000000007;
        }
        return result;
    }
};