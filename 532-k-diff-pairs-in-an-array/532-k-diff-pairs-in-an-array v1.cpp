class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0) return countsame(nums);
        sort(nums.begin(),nums.end());
        unordered_map<int,int>cnt;
        int ans=0;
        int oldnum=1e9;
        for(int num:nums){
            if(num==oldnum) continue;
            if(cnt.count(num)) ans+=cnt[num];
            cnt[num+k]++;
            oldnum=num;
        }
        for(auto item:cnt) cout<<item.first<<" "<<item.second<<endl;
        return ans;
    }
    int countsame(vector<int>&nums){
        int res=0;
        unordered_set<int>st;
        unordered_set<int>counted;
        for(int num:nums){
            if(st.count(num)&& !counted.count(num)) res++,counted.insert(num);
            else st.insert(num);
        }
        return res;
    }
};
