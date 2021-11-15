/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  int ans;
  public:
  int diameter(Node* root) {
    if(root==nullptr) return 0;
    ans=0;
    helper(root);
    return ans;
  }
  int helper(Node* root){
    if(root==nullptr) return -1;
    if(root->children.size()==0) return 0;
    vector<int>cur;
    for(auto child:root->children){
      cur.push_back(helper(child));
      //if(child->val==3) cout<<(child)<<endl;
    }
    sort(cur.begin(),cur.end(),greater());
    //if(root->val==3) {
    //  cout<<cur.size()<<endl;
    //  cout<<cur[0]<<","<<cur[1]<<endl;
    //}
    if(cur.size()>1) ans=max(ans,cur[0]+cur[1]+2);
    else ans=max(ans,cur[0]+1);
    //if(root->val==3) cout<<cur[0]+1<<endl;
    return cur[0]+1;
  }
};