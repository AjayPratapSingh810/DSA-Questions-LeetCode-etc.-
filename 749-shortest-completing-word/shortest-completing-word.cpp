class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans = "";
        int len = INT_MAX;

        vector<char> arr(26,0);
        for(int i=0;i<licensePlate.length();i++){
            if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z'){
                int a = licensePlate[i]-'a';
                arr[a]++;
            }
            else if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z'){
                int a = licensePlate[i]-'A';
                arr[a]++;
            }
        }

        for(int i = 0;i<words.size();i++){
            vector<char> check = arr;
            string test = words[i];
            for(int j=0;j<words[i].size();j++){
                if(test[j] >= 'a' && test[j] <= 'z'){
                    int a = test[j]-'a';
                    check[a]--;
                 }
                else if(test[j] >= 'A' && test[j] <= 'Z'){
                    int a = test[j]-'A';
                    check[a]--;
                }
            }
            bool available = true;
            for(int k = 0;k<check.size();k++){
                if(check[k] > 0){
                    available = false;
                }
            }
            if(available && test.length() < len){
                ans = test;
                len = test.length();
            }
        }
        return ans;

    }
};