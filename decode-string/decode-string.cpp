class Solution {
public:
    string decodeString(string s) {
        stack<string>str;
        stack<int>nums;
        string cur;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int i0=i;
                while(i<s.size()&& isdigit(s[i])) i++;
                int num=stoi(s.substr(i0,i-i0));
                nums.push(num);
                str.push(cur);
                cur="";
            }else if(s[i]==']'){
                int num=nums.top();nums.pop();
                string tmp=cur;
                for(int i=0;i<num-1;i++)
                    cur+=tmp;
                cur=str.top()+cur;
                str.pop();
            }else cur.push_back(s[i]);
        }
        return cur;
    }
};
// 3 [a 2 [3 [c] d]]
// 3 [ a 2 [3 [c] 