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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return nullptr;
        TreeNode* res=new TreeNode(root->val);
        if(root->children.size()) res->left=encode(root->children[0]);
        TreeNode* cur=res->left;
        for(int i=1;i<root->children.size();i++){
            cur->right=encode(root->children[i]);
            cur=cur->right;
        }
        //printBT(res);
        return res;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return nullptr;
        Node* res=new Node(root->val);
        TreeNode* cur=root->left;
        while(cur){
            res->children.push_back(decode(cur));
            cur=cur->right;
        }
        //printNT(res);
        return res;
    }
    void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}
    void printBT(const TreeNode* node)
{
    printBT("", node, false);    
}
        void printNT(const std::string& prefix, const Node* node, bool notLast)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (notLast ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        for(int i=0;i< node->children.size();i++){
            auto child=node->children[i];
            if (i!=node->children.size()-1) printNT( prefix + (notLast ? "│   " : "    "), child, true);
            else printNT( prefix + (notLast ? "│   " : "    "), child, false);
        }
    }
}
    void printNT(const Node* node)
{
    printNT("", node, false);    
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));