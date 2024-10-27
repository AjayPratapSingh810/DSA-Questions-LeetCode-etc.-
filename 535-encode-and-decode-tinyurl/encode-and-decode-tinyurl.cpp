class Solution {
public:
    unordered_map<string,string> encodeMap;
    unordered_map<string,string> decodeMap;
    string baseUrl = "http://tinyurl.com";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeMap.find(longUrl) != encodeMap.end()){
            return encodeMap[longUrl];
        }
        int a = encodeMap.size();
        string s = to_string(a+1);
        string shortUrl =  baseUrl+s;
        encodeMap[longUrl] = shortUrl;
        decodeMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));