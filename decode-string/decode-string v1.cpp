class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        string cur;
        stack<string>str;
        stack<int>nums;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int i0=i;
                while(i<n && isdigit(s[i])) i++;
                int num=stoi(s.substr(i0,i-i0));
                nums.push(num);
                str.push(cur);
                cur="";
            }else if(s[i]==']'){
                int num=nums.top();nums.pop();
                string temp;
                for(int i=0;i<num;i++) temp+=cur;
                cur=str.top()+temp;
                str.pop();
            }else cur.push_back(s[i]);
        }
        return cur;
    }
};
// 3 [a 2 [3 [c] d]]
// 3 [ a 2 [3 [c] 
