class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex = INT_MIN;
        vector<string> strings;
        int i = 0;
        string temp = "";
        while(i<s.length()){
            char a = s[i];
            bool insertion = true;
            
            for(int j=s.length()-1;j>=i;j--){
                if(s[j] == a){
                    temp.push_back(s[i]);
                    i++;
                    if(lastIndex < j){
                        lastIndex = j;
                    }
                    insertion = false;
                    break;
                }
            }
            if(lastIndex < i){
                lastIndex= INT_MIN;
                strings.push_back(temp);
                temp = "";
            }
            if(insertion){
                temp.push_back(s[i]);
                    i++;
            }
        }

        vector<int> ans;
        for(int i=0;i<strings.size();i++){
            string a = strings[i];
            ans.push_back(a.length());
        }
        return ans;
    }
};