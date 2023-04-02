class Solution {
public:
    vector<int>ans;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long s) {
        sort(potions.begin(),potions.end());
        int m=potions.size();
        for(auto& spell:spells){
            int idx=search(potions,spell,s);
            ans.push_back(m-idx);
        }
        return ans;
    }
    int search(vector<int>& potions,int x,long long s){
        int l=0,r=potions.size();
        while(l<r){
            int mid=l+r>>1;
            if((long long)x*potions[mid]>=s) r=mid;
            else l=mid+1;
        }
        return r;
    }
};