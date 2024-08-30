class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(int i=0;i<num.length();i++){
            if(ans.length() == 0){
                ans.push_back(num[i]);
            }else{
                if(ans.back() > num[i] && k > 0){
                    while((ans.length()>0) && (ans.back() > num[i]) &&  k > 0){
                        ans.pop_back();
                        k--;
                    }
                    ans.push_back(num[i]);
                }else{
                    ans.push_back(num[i]);
                }
            }
        }
        while(k>0 && ans.length()>0){
            ans.pop_back();
            k--;
        }
        int size = ans.length();
        int i = 0;
        while(ans[i] == '0'){
            i++;
        }
        if(size-i == 0 ){
            return "0";
        }
        return ans.substr(i,size-i);
    }
};