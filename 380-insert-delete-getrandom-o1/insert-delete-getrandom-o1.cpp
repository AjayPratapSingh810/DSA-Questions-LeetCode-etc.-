class RandomizedSet {
public:
        queue<int>q;
        unordered_map<int,bool> mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp[val]){
            return false;
        }
        q.push(val);
        mp[val] = true;
        return true;
    }
    
    bool remove(int val) {
        if(mp[val] == true){
            while(mp[val]){
                int top = q.front();
            q.pop();
            if(top == val){
                mp[top] = false;
                return true;
            }else{
                q.push(top);
            }
            }
        }
            return false;
    }
    
    int getRandom() {
        int s = q.size();
        int ran = rand()%s;
        while(ran){
            int top = q.front();
            q.pop();
            q.push(top);
            ran--;
        }
        return q.front();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */