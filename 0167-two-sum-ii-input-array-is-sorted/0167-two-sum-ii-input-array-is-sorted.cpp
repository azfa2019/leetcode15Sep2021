class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            int s=numbers[l]+numbers[r];
            if(s==target) break;
            if(s<target) l++;
            if(s>target) r--;
        }
        return {l+1,r+1};
    }
};