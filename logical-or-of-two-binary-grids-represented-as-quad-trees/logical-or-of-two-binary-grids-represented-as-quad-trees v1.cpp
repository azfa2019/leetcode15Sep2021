/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree2->isLeaf) return new Node(quadTree1->val || quadTree2->val,true);
        
        if(quadTree1->isLeaf) {
            if(quadTree1->val==false) return quadTree2;
            else return quadTree1;
        }else if(quadTree2->isLeaf){
            if(quadTree2->val==false) return quadTree1;
            else return quadTree2;
        }
        
        Node* c=new Node();
        c->topLeft=intersect(quadTree1->topLeft,quadTree2->topLeft);
        c->topRight=intersect(quadTree1->topRight,quadTree2->topRight);
        c->bottomLeft=intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
        c->bottomRight=intersect(quadTree1->bottomRight,quadTree2->bottomRight);
        
        if (c->topLeft->isLeaf && c->topRight->isLeaf && c->bottomLeft->isLeaf && c->bottomRight->isLeaf &&
			c->topLeft->val && c->topRight->val && c->bottomLeft->val && c->bottomRight->val) {
            cout<<"hi";
			c=new Node(true, true);
		}
        return c;
    }
};
