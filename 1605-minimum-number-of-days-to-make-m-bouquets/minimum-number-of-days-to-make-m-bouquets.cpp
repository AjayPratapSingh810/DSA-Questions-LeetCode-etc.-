class Solution {
public:
    bool solve(vector<int> &bloomDay,int m,int k,int mid){
        int count = 0;
        for(int i =0;i<=bloomDay.size()-m*k;i++){
            for(int j = i;j<i+m*k;j++){
                int x = k;
                int maxi = INT_MIN;
                while(x){
                    if(bloomDay[j] > maxi){
                        maxi = bloomDay[j];
                    }
                    j++;
                    x--;
                }
                if(maxi <= mid){
                    count++;
                }
            }
            if(count >= m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if((long long)m*k > size){
            return -1;
        }
        int s = 1;
        int e = INT_MAX;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            int cons = 0;
            int boq = 0;
            for(int i = 0;i<bloomDay.size();i++){
                if(bloomDay[i] <= mid){
                    cons++;
                    if(cons >= k){
                        boq++;
                        cons = 0;
                    }
                }else{
                    cons = 0;
                }
            }
            if(boq >= m){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }

        }
        return ans;
    }
};