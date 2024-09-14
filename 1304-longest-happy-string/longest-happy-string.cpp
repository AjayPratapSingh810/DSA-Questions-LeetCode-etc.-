class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int x = a;
        int y = b;
        int z = c;
        string ans = "";
        while(x>0 || y>0 || z>0){
            string s = "";
            if(ans.length() >= 2){
                int i = ans.length() - 2;
                s = ans.substr(i,2);
            }
            bool done = false;

            if((ans.length() < 2 || s != "aa") && x>0 && x >= y && x >= z){
                ans.push_back('a');
                x--;
                done = true;
            }else if((ans.length() < 2 || s != "bb") && y>0 && y >= x && y >= z){
                ans.push_back('b');
                y--;
                done = true;
            }else if((ans.length() < 2 || s != "cc") && z>0 && z > y && z > x){
                ans.push_back('c');
                z--;
                done = true;
            }else if((ans.length() < 2 || s == "aa") && x>=y && x>=z && (y>0 || z>0)){
                if(y > z && y > 0){
                    ans.push_back('b');
                    y--;
                }else if(z>0){
                    ans.push_back('c');
                    z--;
                }
                done = true;
            }else if((ans.length() < 2 || s == "bb") && y>x && y>z && (x>0 || z>0)){
                if(x > z && x > 0){
                    ans.push_back('a');
                    x--;
                }else if(z>0){
                    ans.push_back('c');
                    z--;
                }
                done = true;
            }else if((ans.length() < 2 || s == "cc") && z>y && z>x && (x>0 || y>0)){
                if(x > y && x > 0){
                    ans.push_back('a');
                    x--;
                }else if(y>0){
                    ans.push_back('b');
                    y--;
                }
                done = true;
            }
            if(!done){
                return ans;
            }
        }
        return ans;

    }
};