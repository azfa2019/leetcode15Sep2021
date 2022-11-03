class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int a=0,b=0,c=0;
        unordered_map<string,int>hash;
        for(auto& s:words) hash[s]++;
        for(auto [k,v]:hash){
            if(k[0]==k[1]){
                if(v&1) c++;
                b+=v;
            }else{
                string to="";
                to+=k[1];
                to+=k[0];
                if(hash.count(to)) {
                    a+=2*min(v,hash[to]);
                    hash.erase(to);
                }
            }
        }
        return 2*(a+b-(c<=1?0:c-1));
    }
};