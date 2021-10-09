class Solution {
  public:
  int lengthLongestPath(string input) {
    vector<string>lines;
    for(int i=0;i<input.size();i++){
      int i0=i;
      while(i<input.size()&&input[i]!='\n') i++;
      lines.push_back(input.substr(i0,i-i0));
    }
    //for(int i=0;i<lines.size();i++) cout<<lines[i]<<endl;
    vector<string>level;
    int ans=0;
    for(string line:lines){
      int tabCount=0;
      int curFile=0;
      for(int i=0;i<line.size();i++)
        if(line[i]=='\t') tabCount++;
      if(level.size()<tabCount+1) level.resize(tabCount+1);
      level[tabCount]=line.substr(tabCount);
      //cout<<tabCount<<endl;
      //cout<<level[tabCount]<<endl;
      if(level[tabCount].find(".")!=-1){
        for(int i=0;i<=tabCount;i++) curFile+=level[i].size();
        curFile+=tabCount;// the number of '/'
      }
      ans=max(ans,curFile);
    }

    return ans;
  }
};