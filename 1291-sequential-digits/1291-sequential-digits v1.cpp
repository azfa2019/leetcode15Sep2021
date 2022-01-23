class Solution {
    public:
    vector<int> sequentialDigits(int low, int high) {
        int lowsize=to_string(low).size();
        int highsize=to_string(high).size();
        int lowStart=startingNumber(lowsize);
        int highStart=startingNumber(highsize);
        vector<int>ans;
        for(int j=lowsize;j<=highsize;j++){
            int start=startingNumber(j);
            int end=endingNumber(j);
            for(int i=start;i<=end;i+=ones(j)) {
                if(i>=low && i<=high)
                    ans.push_back(i);
            }
        }
        return ans;
    }
    int startingNumber(int size){
        int s=0;
        for(int i=1;i<=size;i++)
            s=s*10+i;
        return s;
    }
    int endingNumber(int size){
        string s;
        char c='9';
        for(int i=size;i>=1;i--){
            s.push_back(c);
            c=c-1;
        }
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int ones(int size){
        string s(size,'1');
        return stoi(s);
    }

};
