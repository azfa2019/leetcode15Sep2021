class Solution {
public:
    int calculate(string s) {
        string s0="+";
        for(char c:s){
            if(c==' ') continue;
            s0.push_back(c);
            if(c=='(') s0.push_back('+');
        }
        s=s0;
        stack<int>nums;
        stack<int>signs;
        int sum=0;
        int sign=0;
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='+' || ch=='-') sign=ch=='+'?1:-1;
            else if(isdigit(ch)){
                int i0=i;
                while(i<s.size() && isdigit(s[i])) i++;
                int num=stoi(s.substr(i0,i-i0));
                i--;
                sum+=num*sign;
            }else if(ch=='('){
                signs.push(sign);
                nums.push(sum);
                sum=0;
            }else if(ch==')'){
                sum=signs.top()*sum;
                signs.pop();
                sum=nums.top()+sum;
                nums.pop();
            }
        }
        return sum;
    }
};
