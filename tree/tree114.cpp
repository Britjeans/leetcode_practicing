/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curnode=NULL;//=new TreeNode(0);
        TreeNode* prenode=NULL;//=new TreeNode(0);
        bool mark=false;
        while(!s.empty()){
            curnode=s.top();
            if(mark){
                prenode->right=s.top();
                prenode->left=NULL;
            }
            prenode=s.top();
            s.pop();
            if(curnode->right!=NULL){s.push(curnode->right);}
            if(curnode->left!=NULL){s.push(curnode->left);}
            mark=true;
        }
        
    }
};
