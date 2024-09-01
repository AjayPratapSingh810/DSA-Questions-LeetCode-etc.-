class Solution {
public:
    static bool my_compare(const string& a, const string& b) {
        // Compare lexicographically by default
        return a < b;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,string searchWord) {
        sort(products.begin(), products.end(), my_compare);

        vector<vector<string> > ans;
        for(int i =0;i<searchWord.length();i++){
            vector<string> arr;
            string sr = searchWord.substr(0,i+1);
            int count = 0;
            for(int j = 0;j<products.size();j++){
                if(products[j].substr(0,i+1) == sr){
                    arr.push_back(products[j]);
                    count++;
                }
                if(count == 3){
                    break;
                }
            }
            ans.push_back(arr);
        }
        return ans;


    }
};