
class SmallestInfiniteSet {
public:
 
    priority_queue <int, vector<int>, greater<int> > pq;
       unordered_map<int,bool> mp;
    SmallestInfiniteSet() {

        for (int i = 1; i <= 1000; i++){
            pq.push(i);
            mp[i] = true;
        }
    }
    
    int popSmallest() {
        int top = pq.top();
        pq.pop();
        mp[top] = false;
        return top; 
    }
    
    void addBack(int num) {
        if(mp[num] == false){
            mp[num] = true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */