class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i] - x);
            pq.push(make_pair(diff,i));
        }
        int a = k;
        vector<int> ans;
        while(a){
            pair<int,int> top = pq.top();
            pq.pop();
            a--;
            ans.push_back(arr[top.second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};