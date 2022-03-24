class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int res=0;
        for(int i=0,j=people.size()-1;i<=j;){
            if(people[j]+people[i]<=limit) i++,j--;
            else j--;
            res++;
        }
        return res;
    }
};
