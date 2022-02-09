class Solution {
    public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        for(int num:nums) cnt[num]++;
        int res=0;
        if(k==0){
            for(auto item:cnt) 
                if(item.second>=2) res++;
        }
        else{
            for(auto item:cnt)
                if(cnt.count(item.first-k)) res++;
        }
        return res;
    }
};