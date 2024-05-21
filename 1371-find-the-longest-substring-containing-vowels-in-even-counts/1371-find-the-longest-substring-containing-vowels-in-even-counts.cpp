class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>pos(1<<5,-1);
        pos[0]=0;
        int ans=0,status=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='a'){
                status^=(1<<0);
            }else if(c=='e'){
                status^=(1<<1);
            }else if(c=='i'){
                status^=(1<<2);
            }else if(c=='o'){
                status^=(1<<3);
            }else if(c=='u'){
                status^=(1<<4);
            }
            if(pos[status]>=0) ans=max(ans,i-pos[status]+1);
            else pos[status]=i+1;
        }
        return ans;
    }
};