class Solution {
public:
    vector<string> res;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        res.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(size(res)-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.erase(0, 19);
        int x=stoi(shortUrl);
        return res[x];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));