class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        unordered_map<char,int>hash;
        int n=s.size();
        int left=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char r=s[i];
            hash[r]++;
            while(hash[r]>1){
                hash[s[left++]]--;
            } 
            if(i-left+1>k){
                char l=s[left++];
                hash[l]--;
            }
            if(hash[r]==1 && i-left+1==k) ans++;
        }
        return ans;
    }
};