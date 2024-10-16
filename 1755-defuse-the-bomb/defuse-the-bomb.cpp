class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int s = code.size();
        vector<int> ans(s,0);
        if(k == 0){
            return ans;
        }
        if(k < 0){
            k = -k;
            for(int i = 0;i<code.size();i++){
                int sum = 0;
                for(int j = 1;j<=k;j++){
                    if(i-j < 0){
                        int size = code.size();
                        sum = sum + code[size+(i-j)];
                    }else{
                        sum = sum + code[i-j];
                    }
                }
                ans[i] = sum;
            }
        }
        else if(k > 0){
            for(int i = 0;i<code.size();i++){
                int sum = 0;
                for(int j = 1;j<=k;j++){
                    if(i+j >= code.size()){
                        int x = (i+j)%code.size();
                        sum = sum + code[x];
                    }else{
                        sum = sum + code[i+j];
                    }
                }
                ans[i] = sum;
            }
        }
        return ans;

    }
};