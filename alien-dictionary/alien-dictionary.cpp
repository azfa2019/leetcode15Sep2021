class Solution {
  public:
  static string alienOrder(const vector<string> &words) {
    //build the graph first by comparing words[i] and words[i+1], if the first word is larger than the 2nd word and word2 is a prefix of word1, there is no answer
    //if parent!=child, update graph and inDegree, and break
    int n=words.size();
    unordered_map<char,vector<char>>g;
    unordered_map<char,int>indegree;
    for(string w:words) for(char c:w) indegree[c]=0;
    for(int i=0;i<n-1;i++){
      if(words[i].size()>words[i+1].size() && words[i].find(words[i+1])==0) return "";
      for(int j=0;j<min(words[i].size(),words[i+1].size());j++){
        if(words[i][j]==words[i+1][j]) continue;
        g[words[i][j]].push_back(words[i+1][j]);
        indegree[words[i+1][j]]++;
        break;
      }
    }
    queue<char>source;
    for(auto e:indegree) if(e.second==0) source.push(e.first);
    string ans;
    while(!source.empty()){
      char cur=source.front();source.pop();
      ans.push_back(cur);
      for(auto next:g[cur]){
        indegree[next]--;
        if(indegree[next]==0) source.push(next);
      }
    }
    return ans.size()==indegree.size()?ans:"";
  }
};
//class Solution {
//  public:
//  static string alienOrder(const vector<string> &words) {
//    //build the graph first by comparing words[i] and words[i+1], if the first word is larger than the 2nd word and word2 is a prefix of word1, there is no answer
//    //if parent!=child, update graph and inDegree, and break
//    unordered_map<char,vector<char>>graph;
//    unordered_map<char,int>inDegree;
//    queue<char>source;
//    string res="";
//    for(string word:words) for(char c:word) inDegree[c]=0;
//    for(int i=0;i<words.size()-1;i++){
//      string w1=words[i],w2=words[i+1];
//      if(w1.size()>w2.size() && w1.find(w2)==0) return "";
//      for(int j=0;j<min(w1.size(),w2.size());j++){
//        char parent=w1[j],child=w2[j];
//        if(parent!=child){
//          graph[parent].push_back(child);
//          inDegree[child]++;
//          break;
//        }
//      }
//    }
//    
//    for(auto e:inDegree) if(e.second==0) source.push(e.first);
//    while(!source.empty()){
//      char cur=source.front();
//      source.pop();
//      res+=cur;
//      for(auto c:graph[cur]){
//        inDegree[c]--;
//        if(inDegree[c]==0) source.push(c);
//      }
//    }
//    if(res.size()!=inDegree.size()) return "";
//    return res;
//  }
//};

//class Solution {
//  public:
//  static string alienOrder(const vector<string> &words) {
//    if (words.empty() || words.empty()) {
//      return "";
//    }
//    // a. Initialize the graph
//    unordered_map<char, int> inDegree; // count of incoming edges fo
//    unordered_map<char, vector<char>> graph; // adjacency list graph
//    for (auto word : words) {
//      for (char character : word) {
//        inDegree[character] = 0;
//        graph[character] = vector<char>();
//      }
//    }
//    // b. Build the graph
//    for (int i = 0; i < words.size() - 1; i++) {
//      string w1 = words[i], w2 = words[i + 1]; // find ordering of charact
//      if(w1.size()>w2.size() && w1.find(w2)==0) return "";
//      for (int j = 0; j < min(w1.length(), w2.length()); j++) {
//        char parent = w1[j], child = w2[j];
//        if (parent != child) { // if the two characters are dif
//          graph[parent].push_back(child); // put the child into it's paren
//          inDegree[child]++; // increment child's inDegree
//          break; // only the first different character between the two wor
//          // order
//        }
//      }
//    }
//    // c. Find all sources i.e., all vertices with 0 in-degrees
//    queue<char> sources;
//    for (auto entry : inDegree) {
//      if (entry.second == 0) {
//        sources.push(entry.first);
//      }
//    }
//    // d. For each source, add it to the sortedOrder and subtract one from
//    // in-degrees if a child's in-degree becomes zero, add it to the source
//    string sortedOrder;
//    while (!sources.empty()) {
//      char vertex = sources.front();
//      sources.pop();
//      sortedOrder += vertex;
//      vector<char> children = graph[vertex]; // get the node's children to decrement their in-
//      for (char child : children) {
//        inDegree[child]--;
//        if (inDegree[child] ==0) {
//          sources.push(child);
//        }
//      }
//    }
//    // if sortedOrder doesn't contain all characters, there is a cyclic dep
//    // characters, therefore, we will not be able to find the correct order
//    if (sortedOrder.length() != inDegree.size()) {
//      return "";
//    }
//    return sortedOrder;
//  }
//};