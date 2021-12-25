class Solution {
    public:
    int calculate(string s) {
        string s0="+";
        for(char c:s){
            if(c==' ') continue;
            s0.push_back(c);
        }
        s=s0;
        int n=s.size();
        vector<int>nums;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='+' || c=='-'){
                int j=i+1;
                while(j<n && isdigit(s[j])) j++;
                int num=stoi(s.substr(i+1,j-i-1));
                i=j-1;
                if(c=='+')
                    nums.push_back(num);
                else 
                    nums.push_back(-num);
            }else if(c=='*' ||c=='/'){
                int j=i+1;
                while(j<n && isdigit(s[j])) j++;
                int num=stoi(s.substr(i+1,j-i-1));
                i=j-1;
                if(c=='*')
                    nums.back()*=num;
                else 
                    nums.back()/=num;
            }
        }
        int sum=0;
        for(int num:nums) sum+=num;
        return sum;
    }
};
