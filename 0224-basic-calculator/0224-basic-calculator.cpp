class Solution {
public:
    stack<int>num;
    stack<char>op;
    void eval(){
        
        int b=num.top();num.pop();
        int a=num.top();num.pop();
        char c=op.top();op.pop();
        int res;
        if(c=='+') res=a+b;
        else if(c=='-') res=a-b;
        else if(c=='*') res=a*b;
        else res=a/b;
        num.push(res);
    }
    void replace(string& s,string a,string b){
        int pos=s.find(a),n=a.size();
        while(pos!=-1) s.replace(pos,n,b),pos=s.find(a);
    }
    int calculate(string s) {
        replace(s," ","");
        replace(s,"(-","(0-");
        replace(s,"(+","(0+");
        num.push(0);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c==' ') continue;
            if(isdigit(c)) {
                int x=0,j=i;
                while(j<s.size()&&isdigit(s[j])) x=x*10+(s[j++]-'0');
                num.push(x);
                i=j-1;
            }else if(c=='(') op.push(c);
            else if(c==')'){
                while(op.top()!='(') eval();
                op.pop();
            }else{
                while(op.size() && op.top()!='(') eval();
                op.push(c);
            }
        }
        while(op.size()) eval();
        return num.top();
    }
};