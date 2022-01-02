class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>mp(60,0);
        int count=0;
        for(int value:time){
            int remainder=value%60;
            count+=mp[remainder];
            int target=(600-value)%60;
            mp[target]++;
        }
        return count;
    }
};