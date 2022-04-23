class Solution {
    string chars="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string,string>hash;
    string random_str(int k){
        string res;
        while(k--){
            res+=chars[rand()%62];
        }
        return res;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(true){
            string shortUrl=random_str(6);
            if(hash.count(shortUrl)==0){
                hash[shortUrl]=longUrl;
                return "http://tinyurl.com/"+shortUrl;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));