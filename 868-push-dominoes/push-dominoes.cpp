class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = dominoes;

        while(true){
            bool done = false;
            for(int i=0;i<s.length();i++){
                if(s[i]== 'L'){
                    if(i > 0 && s[i-1] == '.'){
                        s[i-1] = 'L';
                        done = true;
                    }
                }else if(s[i] == 'R'){
                    if(i+1 < s.length() && s[i+1] == '.'){
                        if(i+2 < s.length() && s[i+2] == 'L'){
                            i = i+2;
                        }else{
                            s[i+1] = 'R';
                            done = true;
                            i++;
                        }
                    } 
                }
            }
            if(!done){
                break;
            }
        }
        return s;

    }
};