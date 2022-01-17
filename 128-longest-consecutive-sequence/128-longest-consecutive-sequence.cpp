class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num:nums) st.insert(num);
        int ans=0;
        for(auto item:st){
            if(st.find(item-1)!=st.end()) continue;
            int count=0,cur=item;
            while(st.find(cur)!=st.end()) count++,cur++;
            ans=max(ans,cur-item);
        }
        return ans;
    }
};