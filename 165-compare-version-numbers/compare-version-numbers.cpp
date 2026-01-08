class Solution {
public:
    int compareVersion(string version1, string version2) {
        int j = 0;
        int i = 0;
        while(i<version1.length() || j<version2.length()){
            int a = 0;
            int b = 0;
            while(i < version1.length() && version1[i] != '.'){
                int n = version1[i]-'0';
                a *= 10;
                a += n;
                i++;
            }
            while(j < version2.length() && version2[j] != '.'){
                int n = version2[j]-'0';
                b *= 10;
                b += n;
                j++;
            }
            i++;
            j++;
            if(a < b){
                return -1;
            }else if(b < a){
                return 1;
            }
        }
        return 0;
    }
};