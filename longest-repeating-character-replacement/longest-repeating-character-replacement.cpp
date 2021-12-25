class Solution {
    vector<int>count;
    string s;
    int k;
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int j=0;
        this->s=s;
        this->k=k;
        count=vector<int>(26,0);
        for(int i=0;i<s.size();i++){
            while(j<s.size() && checkOk(j,j-i+1)) j++;
            ans=max(ans,j-i);
            count[s[i]-'A']--;
        }
        return ans;
    }
    bool checkOk(int j,int total){
        count[s[j]-'A']++;
        int maxCount=*max_element(count.begin(),count.end());
        if(total-maxCount<=k) return true;
        else{
            count[s[j]-'A']--;
            return false;
        }
    }
};