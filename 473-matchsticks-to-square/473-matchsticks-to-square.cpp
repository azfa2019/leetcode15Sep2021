class Solution {
public:
    vector<int>nums;
    vector<bool>st;
    bool dfs(int start,int cur,int length,int cnt){
        if(cnt==3) return true;
        if(cur==length) return dfs(0,0,length,cnt+1);
        for(int i=start;i<nums.size();i++){
            if(st[i]) continue;
            if(cur+nums[i]<=length){
                st[i]=true;
                if(dfs(i+1,cur+nums[i],length,cnt)) return true;
                st[i]=false;
            }
            if(!cur||cur+nums[i]==length) return false;
            while (i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        nums=matchsticks;
        if(nums.empty()) return false;
        st.resize(nums.size());
        int len=accumulate(nums.begin(),nums.end(),0);
        //cout<<len<<endl;
        if(len%4) return false;
        len/=4;
        //return true;
        sort(nums.begin(),nums.end(),greater<int>());
        return dfs(0,0,len,0);
    }
};