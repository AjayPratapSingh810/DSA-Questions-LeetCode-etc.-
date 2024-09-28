class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()){
            return ans; 
        }
        
        // Frequency maps
        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;

        // Initialize mp for pattern 'p'
        for(char c : p){
            mp[c]++;
        }
        
        // Initialize mp2 for the first window of size p in string s
        int size = p.size();
        for(int i = 0; i < size; i++){
            mp2[s[i]]++;
        }

        // Check if the first window is an anagram
        if(mp == mp2){
            ans.push_back(0);
        }

        // Sliding window across the rest of the string
        int i = 0, j = size;
        while(j < s.length()){
            mp2[s[i]]--; // Remove the character going out of the window
            if(mp2[s[i]] == 0) {
                mp2.erase(s[i]); // Clean up if the count becomes zero
            }
            mp2[s[j]]++; // Add the new character coming into the window
            i++;
            j++;

            // Check if the current window matches the pattern
            if(mp == mp2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
