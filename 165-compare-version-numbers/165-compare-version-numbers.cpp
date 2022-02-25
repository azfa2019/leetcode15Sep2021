class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1=extract(version1);
        auto v2=extract(version2);
        if(compare(v1.first,v2.first)==-1) return -1;
        else if(compare(v1.first,v2.first)==1) return 1;
        else {
            if(v1.second=="" && v2.second=="") return 0;
            else return compareVersion(v1.second,v2.second);
        }
        
    }
    int compare(string& s1,string& s2){
        if(s1=="") s1="0";
        if(s2=="") s2="0";
        if(stoi(s1)>stoi(s2)) return 1;
        else if(stoi(s1)<stoi(s2)) return -1;
        else return 0;
    }
    pair<string,string>extract(string s){
        // 1.01
        // 001
        if(s=="") return {"",""};
        string part1=s;
        string rest="";
        int dotPos=s.find('.');
        if(dotPos!=-1){
            part1=s.substr(0,dotPos);
            rest=s.substr(dotPos+1);
        }
        int i=0;
        while(part1[i]=='0') i++;
        if(i==part1.size()) part1="";
        else part1=part1.substr(i);
        //cout<<part1<<" "<<rest<<"end"<<endl;
        return {part1,rest};
    }
};