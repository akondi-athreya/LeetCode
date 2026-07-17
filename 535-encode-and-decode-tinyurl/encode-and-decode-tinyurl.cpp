class Solution {
public:
    unordered_map<string, string> a, b;
    string base = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (!a.count(longUrl)) {
            string s = base + to_string(a.size()+1);;
            a[longUrl] = s;
            b[s] = longUrl;
        }
        return a[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return b[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));