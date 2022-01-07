class Solution {
    string s;
    int k;
    vector<int>count;
    public:
    int characterReplacement(string s, int k) {
        this->s=s;
        this->k=k;
        this->count=vector<int>(26,0);
        int right=0;
        int n=s.size();
        int ans=0;
        for(int left=0;left<n;left++){
            while(right<n && checkOk(right,right-left+1)) right++;
            ans=max(ans,right-left);
            count[s[left]-'A']--;
        }
        return ans;
    }
    bool checkOk(int right,int total){
        count[s[right]-'A']++;
        int maxCount=*max_element(count.begin(),count.end());
        if(total-maxCount<=k) return true;
        else{
            count[s[right]-'A']--;
            return false;
        }
    }
};