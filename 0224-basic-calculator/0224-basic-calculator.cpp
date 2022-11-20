class Solution {
public:
    int calculate(string s) {
        string s0="+";
        for(char c:s) {
            if(c==' ') continue;
            s0.push_back(c);
            if(c=='(') s0.push_back('+');
        }
        s=s0;
        int n=s.size();
        int sum=0,sign;
        stack<int>signs,nums;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='+' || c=='-'){
                sign=c=='+'?1:-1;
            }else if(isdigit(c)){
                int i0=i;
                while(i<n && isdigit(s[i])) i++;
                int num=stoi(s.substr(i0,i-i0));
                sum+=num*sign;
                i--;
            }else if(c=='('){
                signs.push(sign);
                nums.push(sum);
                sum=0;
            }else if(c==')'){
                sum=sum*signs.top();signs.pop();
                sum=nums.top()+sum; nums.pop();
            }
        }
        return sum;
    }
};