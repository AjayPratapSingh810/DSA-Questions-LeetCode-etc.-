// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        int mid = 1;
        while(s<e){
            mid  = s+(e-s)/2;
            bool is = isBadVersion(mid);
            if(is){
                e = mid;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
};